#include<stdio.h>
void main()
{
 int i,j,k,a[5][5],b[5][5],c[5][5],p,q,r,s,trace=0;
 clrscr();
 printf("enter the order of matrix A\n");
 scanf("%d%d",&p,&q);
 printf("enter the order of matrix B\n");
 scanf("%d%d",&r,&s);
 if(q==r)
 {
  printf("enter the elements of matrix A\n");
  for(i=0;i<p;i++)
   for(j=0;j<q;j++)
    scanf("%d",&a[i][j]);
  printf("enter the elements of matrix b\n");
  for(i=0;i<r;i++)
   for(j=0;j<s;j++)
    scanf("%d",&b[i][j]);
  for(i=0;i<p;i++)
   for(j=0;j<s;j++)
   {
    c[i][j]=0;
    for(k=0;k<r;k++)
     c[i][j]=c[i][j]+a[i][k]*b[k][j];
   }
  printf("matrix C is\n");
  for(i=0;i<p;i++)
  {
   for(j=0;j<q;j++)
    printf("%d\t",c[i][j]);
   printf("\n");
  }
 if(p==r)
 {
  for(i=0;i<p;i++)
   trace=trace+c[i][i];
  printf("trace=%d\n",trace);
 }
}
 getch();
}