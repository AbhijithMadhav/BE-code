#include<stdio.h>
#include<conio.h>
void main()
{
 int a[10],i,key,n,count=0;
 printf("enter the range\n");
 scanf("%d",&n);
 printf("enter the elements of the array\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter the keyword\n");
 scanf("%d",&key);
 for(i=0;i<n;i++)
 if(a[i]==key)
 {
  printf("key element found at %d position\n",i+1);
  count++;
 }
 if(count==0)
 printf("search unsuccessful\n");
 else
 printf("key element found %d times\n",count);
 getch();
}