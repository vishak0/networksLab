set ns [new Simulator]
set nm [open x.nam w]
set tr [open x.tr w]
$ns namtrace-all $nm
$ns trace-all $tr


proc finish {} {
global ns nm tr
$ns flush-trace
close $nm
close $tr
exec nam x.nam &
exec awk -f x.awk x.tr &
exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
#change these both for xgraph vs throughput

$ns duplex-link $n0 $n3 10Mb 10ms DropTail

#Set queue size and Monitor the queue

#Set TCP Connection between n1 and n3
set tcp0 [new Agent/TCP]
$ns attach-agent $n1 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0

#Attach FTP Application over TCP
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type_ FTP

#Set TCP Connection between n2 and n3
set tcp1 [new Agent/TCP]
$ns attach-agent $n2 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1

#Attach Telnet Application over UDP
set telnet [new Application/Telnet]
$telnet attach-agent $tcp1
$telnet set type_ Telnet

#Schedule Events
$ns at 1 "$telnet start"
$ns at 1 "$ftp0 start"
$ns at 21 "$telnet stop"
$ns at 21 "$ftp0 stop"
$ns at 22 "finish"

$ns run
