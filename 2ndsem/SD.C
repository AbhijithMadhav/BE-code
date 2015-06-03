#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
 int a[10],i,key,n,sum=0;
 float mean,sd=0;
 printf("enter the range\n");
 scanf("%d",&n);
 printf("enter the numbers\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 sum=sum+a[i];
 mean=sum/n;
 for(i=0;i<n;i++)
 sd=pow((a[i]-mean),2)+sd;
 sd=sd/n;
 sd=sqrt(sd);
 printf("STANDARD DEVIATION=%f\n",sd);
 getch();
}