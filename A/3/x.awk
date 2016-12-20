BEGIN {
	tcp=0;
	udp=0;
}
{
	pkt=$5;
	if(pkt=="cbr")
		udp++;
	if(pkt=="tcp")
		tcp++;
}
END {
	printf("No of packets sent\nTcp : %d\nUdp : %d\n",tcp,udp);
}
