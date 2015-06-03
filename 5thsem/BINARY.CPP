#include<iostream.h>
#include<conio.h>

int flag,key;

void binary(int a[],int low,int high)
{
 if(high<low)
 {
  flag=0;
  return;
 }
 int mid=(low+high)/2;
 if(a[mid]==key)
 {
  flag=1;
  return;
 }
 if(a[mid]<key)
  binary(a,mid+1,high);
 else
  binary(a,low,mid-1);
}

void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 cin>>key;
 binary(a,0,n-1);
 if(flag)
  cout<<"Found\n";
 else
  cout<<"Not found\n";
 getch();
}


