#include<iostream.h>
#include<conio.h>
struct node
{
 int ce,px,py,flag;
 struct node *link;
};
typedef struct node node;

class polynomial
{
 node *first;
 public:
 polynomial()
 {
  first=NULL;
 }
 void create(int,int,int);
 polynomial operator +(polynomial);
 polynomial operator -(polynomial);
 friend ostream& operator<<(ostream&,polynomial);
};

void polynomial::create(int c,int x,int y)
{
 node *temp=new node;
 temp->flag=0;
 temp->ce=c;
 temp->px=x;
 temp->py=y;
 temp->link=first;
 first=temp;
}

polynomial polynomial::operator +(polynomial s)
{
 node *temp1=first,*temp2;
 polynomial s3;
 while(temp1!=NULL)
 {
  temp2=s.first;
  while(temp2!=NULL)
  {
   if(temp1->px==temp2->px && temp1->py==temp2->py)
   {
    s3.create(temp1->ce+temp2->ce,temp1->px,temp1->py);
    temp2->flag=temp1->flag=1;
   }
   temp2=temp2->link;
  }
  temp1=temp1->link;
 }
 temp1=first;
 while(temp1!=NULL)
 {
  if(temp1->flag==0)
   {
    temp1->flag=1;
    s3.create(temp1->ce,temp1->px,temp1->py);
   }
  temp1=temp1->link;
 }
 temp2=s.first;
 while(temp2!=NULL)
 {
  if(temp2->flag==0)
   {
    temp2->flag=1;
    s3.create(temp2->ce,temp2->px,temp2->py);
   }
  temp2=temp2->link;
 }
 return(s3);
}

polynomial polynomial::operator -(polynomial s)
{
 node *temp1=first,*temp2=s.first;
 while(temp1!=NULL)
 {
  temp1->flag=0;
  temp1=temp1->link;
 }
 while(temp2!=NULL)
 {
  temp2->flag=0;
  temp2=temp2->link;
 }
 temp1=first;
 polynomial s3;
 while(temp1!=NULL)
 {
  temp2=s.first;
  while(temp2!=NULL)
  {
   if(temp1->px==temp2->px && temp1->py==temp2->py)
   {
    s3.create(temp1->ce-temp2->ce,temp1->px,temp1->py);
    temp2->flag=temp1->flag=1;
   }
   temp2=temp2->link;
  }
  temp1=temp1->link;
 }
 temp1=first;
 while(temp1!=NULL)
 {
  if(temp1->flag==0)
   {
    temp1->flag=1;
    s3.create(temp1->ce,temp1->px,temp1->py);
   }
  temp1=temp1->link;
 }
 temp2=s.first;
 while(temp2!=NULL)
 {
  if(temp2->flag==0)
   {
    temp2->flag=1;
    s3.create(-temp2->ce,temp2->px,temp2->py);
   }
  temp2=temp2->link;
 }
 return(s3);
}

ostream& operator<<(ostream &out,polynomial s)
{
 node *temp=s.first;
 while(temp!=NULL)
 {
  out<<"+ ("<<temp->ce<<"x^"<<temp->px<<"y^"<<temp->py<<") ";
  temp=temp->link;
 }
 return(out);
}

void main()
{
 polynomial s1,s2,s3;
 int n,c,x,y;
 cout<<"Enter the no. of elements in the first polynomial\n";
 cin>>n;
 for (int i=0;i<n;i++)
 {
  clrscr();
  cout<<"Coefficient=";
  cin>>c;
  cout<<"\nPower of x=";
  cin>>x;
  cout<<"\nPower of y=";
  cin>>y;
  cout<<endl;
  s1.create(c,x,y);
 }
 cout<<"Enter the no. of elements in the second polynomial\n";
 cin>>n;
 for (i=0;i<n;i++)
 {
  clrscr();
  cout<<"Coefficient=";
  cin>>c;
  cout<<"\nPower of x=";
  cin>>x;
  cout<<"\nPower of y=";
  cin>>y;
  cout<<endl;
  s2.create(c,x,y);
 }
 clrscr();
 cout<<"s1="<<s1<<endl;
  cout<<"s2="<<s2<<endl;
 s3=s1+s2;
 cout<<"Sum="<<s3<<endl;
 s3=s1-s2;
 cout<<"Difference="<<s3<<endl;
 getch();
}



