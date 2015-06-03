#include<iostream.h>
#include<conio.h>
#include<process.h>
#define size 50
template<class type>
class queue
{
 int r,f;
 type q[size];
 public:
 queue()
 {
  r=-1;
  f=0;
 };
 //template<class type>
 void insert(type);
 //template<class type>
 void del();
 int empty();
 int full();
 //template<class type>
 void display();
};

template<class type>
int queue<type>::empty()
{
 if(f>r)
  return(1);
 else
  return(0);
}

template<class type>
int queue<type>::full()
{
 if(r==size-1)
  return(1);
 else
  return(0);
}

template<class type>
void queue<type>::insert(type element)
{
 r++;
  q[r]=element;

}

template<class type>
void queue<type>::del()
{
 type item;
 item=q[f];
 f++;
 cout<<"The deleted item is"<<item;
}

template<class type>
void queue<type>::display()
{
 for(int i=f;i<=r;i++)
  cout<<q[i]<<"\t";
 cout<<endl;
}

void main()
{
 int choice,element;
 double item;
 queue <int> s1;
 queue <double> s2;
 clrscr();
 while(1)
 {
  clrscr();
  cout<<"Enter your choice\n1.Insert\n2.Delete\n3.Exit\n";
  cin>>choice;
  switch(choice)
  {
   case 1 :if(!s1.full())
	   {
	    cout<<"Integer Q\nEnter the element\n";
	    cin>>element;
	    s1.insert(element);
	    s1.display();
	   }
	   else
	    cout<<"Integer Q is full()\n";

	   if(!s2.full())
	   {
	    cout<<"Double Q\nEnter the element\n";
	    cin>>item;
	    s2.insert(item);
	    s2.display();
	   }
	   else
	    cout<<"Double Q is full()\n";
	   getch();
	   break;
   case 2 :if(!s1.empty())
	   {
	    s1.del();
	    s1.display();
	   }
	   else
	    cout<<"Integer Q is empty\n";
	   if(!s2.empty())
	   {
	    s2.del();
	    s2.display();
	   }
	   else
	    cout<<"Double Q is empty\n";
	    getch();
	   break;
   default:exit(0);
  }
 }
}

