#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
 float a,b,c,delta,r1,r2,rp,ip;
 clrscr();
 printf("enter the values of a,b,c\n");
 scanf("%f%f%f",&a,&b,&c);
 if(a==0)
 {
  printf("this is not a quadratic equation\n");
  exit(0);
 }
 delta=(b*b)-(4*a*c);
 if(delta==0)
 {
  r1=-b/(2*a);
  r2=r1;
  printf("the roots are equal and they are,\n r1=r2=%f\n",r1,r1);
 }
 if(delta>0)
 {
  r1=(-b+sqrt(delta))/(2*a);
  r2=(-b-sqrt(delta))/(2*a);
  printf("roots are distinct and are,\n r1=%f\n r2=%f\n",r1,r2);
 }
 if(delta<0)
 {
  rp=-b/(2*a);
  ip=(sqrt(fabs(delta)))/(2*a);
  printf("roots are complex and are,\n r1=%f+i%f\n r2=%f-i%f\n",rp,ip,rp,ip);
 }
getch();
}