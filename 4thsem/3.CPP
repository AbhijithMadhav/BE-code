#include<iostream.h>
#include<conio.h>

template<class type>
int partition(int low,int high,type a[])
{
 int i=low+1,j=high;
 type temp,key=a[low];
 while(1)
 {
  while(key>=a[i]&&i<high)
   i++;
  while(key<a[j])
   j--;
  if(i>j)
  {
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;
   return(j);
  }
  else
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
 }
}

template<class type>
void quicksort(int low,int high,type a[])
{
  int j;
  if(low<high)
  {
   j=partition(low,high,a);
   quicksort(low,j-1,a);
   quicksort(j+1,high,a);
  }
}

void main()
{
  int n;
  clrscr();
  cin>>n;
  int i,a[100];
  for(i=0;i<n;i++)
   cin>>a[i];
  quicksort(0,n-1,a);
  for(i=0;i<n;i++)
   cout<<a[i]<<"\t";
  double d[100];
   for(i=0;i<n;i++)
   cin>>d[i];
  quicksort(0,n-1,d);
  for(i=0;i<n;i++)
   cout<<d[i]<<"\t";
  getch();
}