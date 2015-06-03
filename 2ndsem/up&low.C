#include<stdio.h>
#include<string.h>
void main()
{
 char a[100];
 int i;
 printf("enter the given string\n");
 gets(a);
 for(i=0;a[i]!='\0';i++)
  {
   if(isupper(a[i]))
    a[i]=tolower(a[i]);
    else
    a[i]=toupper(a[i]);
  }
 printf("converted string\n");
 puts(a);
 getch();
}
