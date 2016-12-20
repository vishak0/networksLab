#include <iostream>
using namespace std;

int calc(string data,int checksum)
{
	int sum=0;
  for(int i=0; i<data.length();i++)
	   sum+=(i%2==0)? data[i]*256:data[i];
  sum+=checksum;
  sum = sum/65536 + sum%65536;
	return 65535-sum;
}


int main()
{
	string data;
	int checksum;

	cout<<"Dataword:\n";
	cin>>data;
	checksum = calc(data,0);
	cout<<"Checksum= "<<hex<<checksum<<endl;

	cout<<"\nReceived Dataword:\n";
	cin>>data;
	cout<<"Checksum:\n";
	cin>>hex>>checksum;
	checksum = calc(data,checksum);

	if(checksum!=0)
 	  cout<<"Errors detected\n";
  else
    cout<<"No Errors\n";

  return 0;

}
