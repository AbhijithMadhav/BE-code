#include<iostream.h>
#include<conio.h>
struct node
{
 int info;
 struct node *link;
};
typedef struct node node;

class list
{
 node *first;
 public:
 void create(char[]);
 list operator -(list);
 friend ostream& operator <<(ostream&,list);
 list()
 {
  first=NULL;
 }
}
;

void list::create(char a[])
{
 node *temp,*cur;
 for(int i=0;a[i]!='\0';i++)
 {
  temp=new node;
  temp->info=a[i]-'0';
  temp->link=NULL;
  if(first==NULL)
   first=temp;
  else
  {
   temp->link=first;
   first=temp;
  }
 }
}

list list::operator-(list s)
{
 char a[100];
 int i=0;
 node *temp1,*temp2,*p;
 temp1=first;
 temp2=s.first;
 while(temp2!=NULL)
 {
  if(temp1->info>=temp2->info)
  {
   a[i]=temp1->info-temp2->info+'0';
   i++;
   temp1=temp1->link;
   temp2=temp2->link;
  }
  else
  {
   if(temp1->link->info==0)
   {
    p=temp1->link;
    while(p->info==0)
    {
     p->info=9;
     p=p->link;
    }
    p->info--;
   }
   else
    temp1->link->info--;
   temp1->info+=10;
   a[i]=temp1->info-temp2->info+'0';
   i++;
   temp1=temp1->link;
   temp2=temp2->link;
  }
 }
 while(temp1!=NULL)
 {
  a[i]=temp1->info+'0';
  i++;
 }
 a[i]='\0';
 list s3;
 s3.create(a);
 return(s3);
}

ostream& operator <<(ostream& out,list s)
{
 node *temp=s.first;
 while(temp!=NULL)
 {
  out<<temp->info;
  temp=temp->link;
 }
 return(out);
}

void main()
{
 list s1,s2,s3;
 clrscr();
 char a[100],b[100];
 cin>>a;
 s1.create(a);
 cin>>a;
 s2.create(a);
 s3=s1-s2;
 cout<<s3;
 getch();
}
