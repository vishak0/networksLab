BEGIN {
	s=0;
	Tput = 0;
}
{
	event = $1;
	size = $6;
	time = $2;

	if (event == "r")
	s+=size;

	Tput = (s/4.0)*(8/1000);
	printf("%f \t %.2f \n",time,Tput);

}
END {

}
