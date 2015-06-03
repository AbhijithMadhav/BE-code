#include<iostream.h>
#include<conio.h>
#include<process.h>


class task
{
 int s,f,assigned_machine;
 public:
// void swap(task&);
 void friend schedule(int,int);
 void display(int);
 void input();
};

class machine
{
 int s,f;
 public:
 void friend schedule(int, int);
 machine()
 {
  s=f=0;
 }
};

/*void task::swap(task &a)
{
 task temp;
 temp=a;
 a=*this;
 *this=temp;
} */

void task::input()
{
 cout<<"Enter the start and finish timings\n";
 cin>>s>>f;
}

void task::display(int i)
{
 cout<<"  "<<i<<"      "<<assigned_machine<<"      "<<s<<"       "<<f<<endl;
}

void schedule(int nm,int nt)
{
 task t[10];
 for(int i=1;i<=nt;i++)
  t[i].input();
 machine m[10];
 for(i=1;i<=nt-1;i++)
 {
  int small=i;
  for(int j=i+1;j<=nt;j++)
   if(t[small].s > t[j].s)
    small=j;
  //t[i].swap(t[small]);
  int temp;
  temp=t[i].s;
  t[i].s=t[small].s;
  t[small].s=temp;
  temp=t[i].f;
  t[i].f=t[small].f;
  t[small].f=temp;
 }
   cout<<"TASK  MACHINE  START  FINISH\n";
 for(i=1;i<=nt;i++)
 {
  int schedule=0;
  for(int j=1;j<=nm;j++)
   if(m[j].f<=t[i].s)
   {
    m[j].s=t[i].s;
    m[j].f=t[i].f;
    t[i].assigned_machine=j;
    schedule=1;
    break;
   }
  if(!schedule)
  {
    cout<<"Number of machines not sufficient\n";
    getch();
    exit(0);
   }
 }
 if(schedule)
 {
  for(i=1;i<=nt;i++)
  t[i].display(i);
 }
}

void main()
{
 cout<<"Enter the no. of machines\n";
 int nm,nt;
 cin>>nm;
 cout<<"Enter the no. of tasks\n";
 cin>>nt;
 schedule(nm,nt);
 getch();
}