#include<iostream.h>
#include<conio.h>

void simmerge(int a[],int low,int mid,int high)
{
 int i=low;
 int j=mid+1;
 int temp[19];
 int k=0;
 while(i<=mid && j<=high)
 {
  if(a[i]<a[j])
   temp[k++]=a[i++];
  else
   temp[k++]=a[j++];
 }
 while(j<=high)
   temp[k++]=a[j++];
 while(i<=mid)
   temp[k++]=a[i++];
  k=0;
 for(i=low;i<=high;i++)
  a[i]=temp[k++];
}

void mergesort(int a[],int low,int high)
{
 if(low<high)
 {
  int mid=(low+high)/2;
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  simmerge(a,low,mid,high);
 }
}

void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 mergesort(a,0,n-1);
 for(i=0;i<n;i++)
  cout<<a[i] ;
 getch();
}





