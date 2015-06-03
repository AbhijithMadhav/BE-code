#include<stdio.h>
long int fact(int);
void main()
{
 long int npr,ncr;
 int n,r;
 printf("enter the values of n&r\n");
 scanf("%d%d",&n,&r);
 npr=fact(n)/fact(n-r);
 ncr=fact(n)/(fact(n-r)*fact(r));
 printf("nPr=%ld\nnCr=%ld",npr,ncr);
 getch();
}
/****************************************************************/
long int fact(int m)
{
 long int factorial=1;
 int i;
 for(i=1;i<=m;i++)
 factorial=factorial*i;
 return(factorial);
}