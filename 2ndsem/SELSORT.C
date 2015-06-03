/*#include<stdio.h>
void main()
{
 int i,n,a[10];
 clrscr();
 printf("Enter the range of the array\n");
 scanf("%d",&n);
 printf("enter the elements of the array\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 void sort(n,a);
 getch();
}


void sort(int n,int a[10])
{
 int j,dummy;
 for(j=n-1;j>=1;j--)
 {
  dummy=a[max(j,a)];
  a[max(j,a)]=a[j];
  a[j]=dummy;
 }
 printf("sorted array is\n");
 for(j=0;j<n;j++)
  printf("%d\t",a[j]);
}



max(int j,int a[10])
{
 int t,maxi=0;
 for(t=0;t<=j;t++)
 {
  if(a[t]>a[maxi])
   maxi=t;
 }
 return(maxi);
}*/


#include<stdio.h>
void main()
{
 int a[10],n,i,j;
 void max();
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the elements of the array\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
    max(a,i,j);
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
 getch();
}


void max(int a[10],int i,int j)
{

 if(a[j]>a[i])
  exchange(i,j,a);
}


exchange(int i,int j,int a[10])
{
 int dummy;
 dummy=a[i];
 a[i]=a[j];
 a[j]=dummy;
}












