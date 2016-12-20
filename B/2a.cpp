#include<iostream>
using namespace std;

int main()
{
  int cap,t,j;
  float orate;

  cout<<"Set output rate\n";
  cin>>orate;
  cout<<"Set bucket size\n";
  cin>>cap;
  cout<<"Set time range\n";
  cin>>t;

  int X=t+cap+10;
  int bucket[X];
  int buffer[X];
  bool dropped[X];

  for (int i = 0; i < X; i++)
  {
      bucket[i]=0;
      dropped[i]=false;
      buffer[i]=0;
  }


  for (int i = 0; i < t; i++)
  {
      cout<<"Packet at second "<<i<<endl;
      cin>>buffer[i];
  }


  for (int i = 0; i < t; i++)
  {
      if(bucket[i]+buffer[i] <= cap)
      {
          bucket[i]+=buffer[i];
          int temp=bucket[i];
          j=i+1;
          while ((temp-=orate)>0 && j<X)
              bucket[j++]=temp;
      }
      else
          dropped[i]=true;
  }

  cout<<"\nTime recieved  dropped  remained \n";
  for (int i = 0; i < j; i++)
      cout<<i<<"\t"<<buffer[i]<<"\t"<<boolalpha<<dropped[i]<<"\t\t"<<bucket[i]<<"\t\n";



    }
