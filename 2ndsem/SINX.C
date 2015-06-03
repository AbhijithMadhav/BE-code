/*#include<stdio.h>
#include<math.h>
void main()
{
 int n,choice,den,i;
 float x,sinvalue,term,acc,sinx;
 clrscr();
 printf("enter the value of x\n");
 scanf("%f",&x);
 x=3.142*x/180;
 sinvalue=sin(x);
 do
 {
  printf("Menu\n");
  printf("1.Sine value to a given accuracy\n");
  printf("2.Sine value upto a n terms\n");
  printf("3.Exit\n");
  printf("Enter UR choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("enter the accuracy\n");
	  scanf("%f",&acc);
	  term=x;
	  sinx=x;
	  n=1;
	  do
	  {
	   den=2*n*(2*n+1);
	   term=-term*x*x/den;
	   sinx=sinx+term;
	   n++;
	  }
	  while(acc<=fabs(sinvalue-sinx));
	  printf("sinx=%f",sinx);
	  break;
   case 2:printf("enter the number of terms \n");
	  scanf("%d",&n);
	  term=x;
	  sinx=x;
	  for(i=1;i<n;i++)
	  {
	   term=-term*x*x/(2*i*(2*i+1));
	   sinx=sinx+term;
	  }
	  printf("sinx=%f",sinx);
	  break;
   case 3:exit(0);
   default:printf("invalid choice\n");
	   getch();
	   exit(0);
  }
 }
 while(choice>=1&&choice<=2);
 getch();
}*/
#include<stdio.h>
#include<math.h>
void main()
{
 float acc,x,term,sinx,x1;
 int choice,n,i;
 printf("enter the value of x\n");
 scanf("%f",&x);
 x1=x;
 x=x*(3.1412/180);
 do
 {
  printf("MENU\n");
  printf("1.sine value by accuracy\n");
  printf("2.sine value by no. of terms\n");
  printf("3.EXIT\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("enter the accuracy\n");
	  scanf("%f",&acc);
	  term=x;
	  sinx=x;
	  n=1;
	  do
	  {
	   term=-term*x*x/(2*n*(2*n+1));
	   sinx=sinx+term;
	   n++;
	  }
	  while(acc<=fabs(sin(x)-sinx));
	  printf("sin%f=%f(using accuracy)\n",x1,sinx);
	  printf("sin%f=%f(using library functions)\n",x1,sin(x));
	  break;
   case 2:printf("enter the number of terms\n");
	  scanf("%d",&n);
	  term=x;
	  sinx=x;
	  for(i=1;i<=n;i++)
	  {
	   term=-term*x*x/(2*i*(2*i+1));
	   sinx=sinx+term;
	  }
	  printf("sin%f=%f(using no. of terms)\n",x1,sinx);
	  printf("sin%f=%f(using library functions)\n",x1,sin(x));
	  break;
   case 3:exit(0);
  }
 }
 while(choice==1||choice==2);
}