/*#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
 int i,j,num,flag,count=0;
 printf("\nEnter the number\n");
 scanf("%d",&num);
 if(num==0||num==1)
 printf("there are no prime numbers\n");
 else
 {
  printf("The prime numbers upto %d are\n",num);
  for(i=2;i<num;i++)
  {
   flag=0;
   for(j=2;j<=i/2;j++)
   {
    if(i%j==0)
    {
     flag=1;
     break;
    }
   }
   if(flag==0);
   {
    printf("%d\t",i);
    count++;
   }
  }
  printf("\nThe number of prime numbers upto %d=%d\n",num,count);
 }
 getch();
}*/
#include<stdio.h>
void main()
{
 int n,i,j,flag,count=0;
 printf("enter the number\n");
 scanf("%d",&n);
 printf("the prime numbers are\n");
 for(i=2;i<n;i++)
 {
  flag=1;
  for(j=2;j<=i/2;j++)
  {
   if(i%j==0)
   {
    flag=0;
    break;
   }
  }
  if(flag==1)
  {
   printf("%d\t",i);
   count++;
  }
 }
 printf("\nthe number of prime numbers=%d\n",count);
 getch();
}


