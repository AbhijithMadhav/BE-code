#include<stdio.h>
#include<conio.h>
void main()
{
 int a[30],i,j,flag=0,n,dummy,key,high,low,mid,probe=0;
 clrscr();
 printf("Enter the range\n");
 scanf("%d",&n);
 printf("enter the elements of the array\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
/*bubble sort begins*/
 for(i=0;i<(n-1);i++)
  for(j=0;j<(n-i-1);j++)
   if(a[j]>a[j+1])
   {
    dummy=a[j];
    a[j]=a[j+1];
    a[j+1]=dummy;
   }
 printf("sorted array:\n");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
/*sorting over*/
 printf("\n enter the key element to be searched\n");
  scanf("%d",&key);
 low=0;
 high=n-1;
 while((low<high)&&(flag==0))
 {
  probe++;
  mid=(high+low)/2;
  if(key==a[mid])
  {
   flag=1;
   printf(" element found at position %d\n",mid+1);
   break;
  }
  if(key>a[mid])
   low=mid+1;
  else
   high=mid-1;
 }
 if(flag==0)
 printf("search unsuccessful\n");
 else
 printf("number of probes=%d\n",probe);
 getch();
}












