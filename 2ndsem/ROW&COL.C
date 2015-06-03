#include<stdio.h>
void main()
{
 int r,c,a[5][5],j,i;
 clrscr();
 printf("Enter the order of the matrix\n");
 scanf("%d%d",&r,&c);
 printf("enter the elements of the matrix\n");
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   scanf("%d",&a[i][j]);
 printf("input matrix is\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   printf ("%d\t",a[i][j]);
  printf("\n");
 }
 sumr(r,c,a);
 sumc(r,c,a);
 getch();
}

sumr(int r,int c,int a[5][5])
{
 int sum,i,j;
 for(i=0;i<r;i++)
 {
  sum=0;
  for(j=0;j<c;j++)
   sum=sum+a[i][j];
  printf("sum of row%d=%d\n",i+1,sum);
 }
}

 sumc(int r,int c,int a[5][5])
{
 int sum,i,j;
 for(i=0;i<c;i++)
 {
  sum=0;
  for(j=0;j<r;j++)
   sum=sum+a[j][i];
  printf("sum of column%d=%d\n",i+1,sum);
 }
}

