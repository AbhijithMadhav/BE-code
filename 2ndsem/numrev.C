
/*to get a number in the reverse order*/
#include<stdio.h>
#include<math.h>
void main()
{
 int num1,num,sum=0,numrev=0,digit;
  char another='y';
  while(another=='y')
  {
  clrscr();
  printf("enter the number:\n");
  scanf("%d",&num);
  num1=num;
  while(num!=0)
  {
   digit=num%10;
   num=num/10;
   sum=sum+digit;
   numrev=numrev*10+digit;
  }
  printf("the number in reverse order is %d\n",numrev);
  printf("sum of digits=%d\n",sum);
  if(numrev=num1)
  printf("dfsd\n");
  printf("\ndo you want to continue(y/n)");
  scanf("\n%c",&another);
  }
  getch();
}
