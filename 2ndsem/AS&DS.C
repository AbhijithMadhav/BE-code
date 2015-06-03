#include<stdio.h>
void main()
{
 int n,a[10],fa=1,fd=1,i;
 printf("enter the range of numbers\n");
 scanf("%d",&n);
 printf("enter the numbers\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 for(i=0;i<n-1;i++)
  {
   if(a[i]>a[i+1])
   {
    fa=0;
    break;
   }
  }
 for(i=0;i<n-1;i++)
  {
   if(a[i]<a[i+1])
   {
    fd=0;
    break;
   }
  }
 if(fa==1)
  printf("vector is in ascending order\n");
 if(fd==1)
  printf("vector is in descending order\n");
 if(fd==0&&fa==0)
  printf("vector is not sorted\n");
 getch();
}