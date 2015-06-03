#include<stdio.h>
void main()
{
 int a[10],i,sump=0,sumn=0,abv=0,bel=0;
 float avg,sum=0;
 printf("Enter the ten numbers\n");
 for(i=0;i<10;i++)
  scanf("%d",&a[i]);
 for(i=0;i<10;i++)
 {
  if(a[i]>0)
   sump+=a[i];
  else
   sumn+=a[i];
  sum+=a[i];
 }
 avg=sum/10;
 for(i=0;i<10;i++)
 {
  if(a[i]>avg)
   abv++;
  if(a[i]<avg)
   bel++;
  }
 printf("sump=%d\nsumn=%d\navg=%f\nabv=%d\nbel=%d\n",sump,sumn,avg,abv,bel);
 getch();
}