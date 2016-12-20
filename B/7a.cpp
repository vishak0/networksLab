#include <iostream>
#include <list>
using namespace std;
list<int> q1,q2;


int choice()
{
  int x;
  cout<<"\n1. Enqueue high\n2. Enqueue low\n3. Dequeue\n";
  cin>>x;
  return x;
}

void display()
{
  cout<<"\nHigher order: ";
  for (list<int>::iterator i = q1.begin(); i != q1.end(); ++i)
    cout << *i <<" ";
  cout<<"\nLower order: ";
  for (list<int>::iterator i = q2.begin(); i != q2.end(); ++i)
    cout << *i <<" ";
  cout<<endl;
}

void enque(list<int> &q)
{
  int data;
  cout<<"Enter data\n";
  cin>>data;
  q.push_back(data);
  display();
}

void deque()
{
  if(!q1.empty())
  {
    cout<<"\nSent: "<<q1.front()<<endl;
    q1.pop_front();
  }
  else if(!q2.empty())
  {
    cout<<"\nSent: "<<q2.front()<<endl;
    q2.pop_front();
  }
  else
  cout<<"\nEmpty queues\n";
  display();
}

int main()
{
   int x;

   while(true)
   {
     x=choice();

     if(x==1)
        enque(q1);

     else if(x==2)
        enque(q2);

     else if(x==3)
        deque();

     else return 0;
   }

}
