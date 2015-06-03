#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
 int i,num,flag=1;
 printf("\nEnter the number\n");
 scanf("%d",&num);
 for(i=2;i<=num/2;i++)
 {
  if(num%i==0)
  {
   flag=0;
   break;
  }
 }
 if(flag==1)
 {
  printf("%d is a prime number\n",num);
 }
 else
  printf("%d is not a prime number\n",num);
 getch();
}