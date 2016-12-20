BEGIN {
	dcount = 0;
	rcount = 0;
}
{
	event = $1;
	time = $2;
	if(event == "d")
		dcount++;

	if(event == "r")
		rcount++;

	if(event == "r" ||  event == "d")
				print time"	"dcount>>"values.txt"
}
END {
	printf("The no.of packets dropped  : %d\n ",dcount);
	printf("The no.of packets recieved : %d\n ",rcount);
}
