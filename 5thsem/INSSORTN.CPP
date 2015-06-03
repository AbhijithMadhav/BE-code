#include<iostream.h>
#include<conio.h>

void insertionsort(int a[],int n)
{
 for(int i=1;i<=n-1;i++)
 {
  int temp=a[i];
  for(int j=i-1;j>=0;j--)
   if(a[j]>temp)
    a[j+1]=a[j];
   else
    break;
  a[j+1]=temp;
 }
}

void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 insertionsort(a,n);
 for(i=0;i<n;i++)
  cout<<a[i] ;
 getch();
}


