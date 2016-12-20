
BEGIN {
	FTP=0;
	Telnet=0;
}

{
	event=$1;
	pkt= $5;
	from=$9;
	to=$10;

	if(event == "r" && pkt == "tcp")
	{
		if(from == "1.0" )
			FTP++;
		else if(from == "2.0")
			Telnet++;
	}

}

END {
	T_FTP= FTP*416; # because *8*1040/24
	T_Telnet= Telnet*416; # because simulation time is 24.5 ­ 0.5 = 24
	printf("The Throughput of FTP application is %d \n", T_FTP);
	printf("The Throughput of TELNET application is %d \n", T_Telnet);
}
