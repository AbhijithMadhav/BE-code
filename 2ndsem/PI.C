#include<stdio.h>
#include<math.h>
void main()
{
 float acc,pi=0,term,n=1;
 printf("enter the accuracy\n");
 scanf("%f",&acc);
 while(1)
 { term=6/(n*n);
  if(term>=acc)
  {
   pi=pi+term;
   n=n+1;
  }
  else
   break;
 }
 pi=sqrt(pi);
 printf("pi=%f\n",pi);
 getch();
}