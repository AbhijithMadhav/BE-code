#include<iostream.h>
#include<conio.h>

class student
{
 protected:
 int age;
 char name[10];
};

class ug:public student
{
 int sem;
 public:
 void read();
 int sum(int);
};

void ug::read()
{
 cin>>name>>age>>sem;
}

int ug::sum(int i)
{
 if(i==sem)
  return(age);
 else
  return(0);
}

void main()
{
 ug u[6];
 int s,n,avg,test;
 for(int a=1;a<=5;a++)
  u[a].read();
 for(int i=1;i<=8;i++)
 {
  s=0;
  n=0;
  for(int j=1;j<=5;j++)
  {
   test=s;
   s+=u[j].sum(i);
   if(test==s)  ;
    else
    n++;
  }
  if(n==0)
   avg=s;
  else
   avg=s/n;
  cout<<"Average age of"<<i<<"semester students="<<avg<<endl;
 }
 getch();
}