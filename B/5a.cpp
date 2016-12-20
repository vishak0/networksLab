#include <iostream>
#include<string>
#include <bitset>
#include <cstdlib>
using namespace std;


string divide(string code,string gen)
{
  for (int i = 0; i < code.length()-gen.length()+1; i++) {

    if(code[i]=='0')
        continue;

    for (int j = i; j < i+gen.length(); j++)
    {
      if(code[j]==gen[j-i])
          code[j]='0';
      else
          code[j]='1';
    }
  }
  return code.substr(code.length()-16);

}


int main()
{
  string data,code,gen,rem;

  cout<<"Dataword:\n";
  cin>>data;
  cout<<"Generator (17 bit):\n";
  int g;
  cin>>hex>>g;

  gen = bitset<17>(g).to_string();
  code = data + "0000000000000000";
  rem = divide(code,gen);
  cout<<"CRC-16= "<<rem<<endl;

  cout<<"Enter received code\n";
  cin>>code;
  rem = divide(code,gen);

  if(rem!="0000000000000000")
    cout<<"Errors detected\n";
  else
    cout<<"No Errors\n";




  //code.replace(code.end()-16,code.end(),rem);
}
