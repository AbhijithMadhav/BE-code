#include<iostream.h>
#include<conio.h>
/*void swap(int &b,int &c)
{

}*/

void selsort(int a[],int n)
{
 for(int i=0;i<n-1;i++)
 {
  int small=i;
  for(int j=i+1;j<n;j++)
  {
   if(a[small]>a[j])
    small=j;
  }
  int temp;
  temp=a[small];
  a[small]=a[i];
  a[i]=temp;
  //swap(a[pos],a[i]);
 }
}


void main()
{
 int n,a[19];
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 selsort(a,n);
 for(i=0;i<n;i++)
  cout<<a[i] ;
 getch();
}



