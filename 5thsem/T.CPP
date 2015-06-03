#include<iostream.h>
#include<conio.h>
class task
{
 int s,f;
 public:
 void swap(task&);
 void friend asd(task,task);
 void as(task &w)
 {
  cout<<(*this).s<<(*this).f<<endl;
  cout<<w.s<<w.f;
 }
}q,w;
void asd(task q,task w)
 {
  q.s=q.f=1;
  w.s=w.f=2;
 }
 void task::swap(task &a)
{
 task temp;
 temp=a;
 a=*this;
 *this=temp;
}

void main()
{
// task q,w;
 asd(q,w);
 q.swap(w);
 q.as(w);
 getch();
}