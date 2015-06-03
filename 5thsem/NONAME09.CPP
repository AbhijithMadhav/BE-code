#include<iostream.h>
#include<conio.h>
class task
{
 int s,f;
 public:
 void swap(task&);
 void friend asd()
 {
  q.s=q.f=1;
  w.s=w.f=2;
 }
}q,w;

 void task::swap(task &a)
{
 task temp;
 temp=a;
 a=*this;
 *this=temp;
}

void main()
{
 asd();
 q.swap(w);
 getch();
}