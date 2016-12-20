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
#set color to the nodes
$ns color 1 blue

$n1 label TCP
$n2 label UDP
$n3 label NULL-TCPSINK

$ns duplex-link $n1 $n0 1Mb 10ms DropTail
$ns duplex-link $n2 $n0 1Mb 10ms DropTail
#change Bandwidth for xgraph vs no. of packets recieved
$ns duplex-link $n0 $n3 1Mb 10ms DropTail

set tcp0  [new Agent/TCP]
$ns attach-agent $n1 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0
$tcp0 set fid_ 1

set ftp0  [new Application/FTP]
$ftp0 attach-agent $tcp0

set udp0 [new Agent/UDP]
$ns attach-agent $n2 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

$ns at 0.2 "$cbr0 start"
$ns at 0.1 "$ftp0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 4.4 "$ftp0 stop"

$ns at 5.0 "finish"
$ns run
