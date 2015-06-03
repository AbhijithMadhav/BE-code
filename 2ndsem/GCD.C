#include<stdio.h>
void main()
{
 int a,b,rem,c;
 clrscr();
 printf("Enter the two numbers\n");
 scanf("%d%d",&a,&b);
 c=a*b;
 rem=a%b;
 while(rem!=0)
 {
  a=b;
  b=rem;
  rem=a%b;
 }
 printf("GCD=%d\n",b);
 printf("LCM=%d",c/b);
 getch();
}
