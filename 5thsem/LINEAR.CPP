#include<iostream.h>
#include<conio.h>

int flag,key;

void linear(int a[],int i)
{
 if(i==-1)
 {
  flag=0;
  return;
 }
 else if(a[i]==key)
 {
  flag=1;
  return;
 }
 linear(a,i-1);
}

void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 cin>>key;
 linear(a,n-1);
 if(flag)
  cout<<"Found\n";
 else
  cout<<"Not found\n";
 getch();
}

