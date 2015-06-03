#include<stdio.h>
#include<string.h>
void main()
{
 char name[15][15],dummy[15];
 int i,j;
 clrscr();
 printf("enter 10 names\n");
 for(i=0;i<10;i++)
  scanf("%s",&name[i]);
 for (i=0;i<9;i++)
  for(j=i+1;j<10;j++)
  {
   if(strcmp(name[i],name[j])>0)
   {
    strcpy(dummy,name[i]);
    strcpy(name[i],name[j]);
    strcpy(name[j],dummy);
   }
  }
 printf("the names in the alphabetical order are\n");
 for(i=0;i<10;i++)
  printf("%s\n",name[i]);
 getch();
}