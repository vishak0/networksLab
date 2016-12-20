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

$ns duplex-link $n0 $n1 1Mb 5ms DropTail
#change this for xgraph vs no. of packets recieved
$ns duplex-link $n1 $n2 100Kb 5ms DropTail
$ns queue-limit $n1 $n2 10



set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp0 $null

$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
