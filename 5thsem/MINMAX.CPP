#include<iostream.h>
#include<conio.h>

int max,min;

void minmax(int a[],int i)
{
 if(i==-1)
  return;
 if(min>a[i])
  min=a[i];
 if(max<a[i])
  max=a[i];
 minmax(a,i-1);
}

 void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 min=max=a[n-1];
 minmax(a,0);
 cout<<max<<min;
 getch();
}