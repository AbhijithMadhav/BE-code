#include<stdio.h>
#include<string.h>
void main()
{
 int count=0,j;
 char b[10];
 printf("enter the string\n");
 gets(b);
 for(j=0;b[j]!='\0';j++)
  switch(b[j])
  {
   case 'a':
   case 'e':
   case 'o':
   case 'i':
   case 'u':count++;
  }
 printf("number of vowels=%d\n",count);
 getch();
 }
