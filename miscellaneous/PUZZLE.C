
int c=63;
void main()
{
 char direction;
 int i,j,c1=3,c2=3;
 int a[4][4]={2,1,13,4,15,3,7,10,14,5,11,12,8,9,6,63};
 int move=0,dummy;
 void print(int a[4][4],int c1,int c2,int move);
 print(a,c1,c2,move);
 i=3;
 j=3;
 while(ascending(a)==0)
 {
  scanf("%c",&direction);
  switch(direction)
  {
   case 'd':if(i>0)
	    {
	     dummy=a[i-1][j];
	     a[i-1][j]=a[i][j];
	     a[i][j]=dummy;
	     i=i-1;
	     c1=i;
	     c2=j;
	     move++;
	     print(a,c1,c2,move);
	    }
	     break;
   case 'u':if(i<3)
	    {
	     dummy=a[i+1][j];
	     a[i+1][j]=a[i][j];
	     a[i][j]=dummy;
	     i=i+1;
	     c1=i;
	     c2=j;
	     move++;
	     print(a,c1,c2,move);
	    }
	    break;
   case 'l':if(j<3)
	    {
	     dummy=a[i][j+1];
	     a[i][j+1]=a[i][j];
	     a[i][j]=dummy;
	     j=j+1;
	     c1=i;
	     c2=j;
	     move++;
	    }
	    print(a,c1,c2,move);
	    break;
   case 'r':if(j>0)
	    {
	     dummy=a[i][j-1];
	     a[i][j-1]=a[i][j];
	     a[i][j]=dummy;
	     j=j-1;
	     c1=i;
	     c2=j;
	     move++;
	    }
	    print(a,c1,c2,move);
	    break;
   case 'e':printf("BOY,YOU DONT HAVE IT IN YOU.YOU ARE A BLOODY LOSER.");
	    getch();
	    exit(0);
   }
 }
}

//=========================================================================

ascending(int a[4][4])
{
 int m,n,p=0,b[50],flag=1;
 for(m=0;m<3;m++)
 for(n=0;n<3;n++,p++)
 b[p]=a[m][n];
 for(p=0;p<15;p++)
 if(b[p]>b[p+1])
 {
  flag=0;
  break;
 }
 return(flag);
}

//=========================================================================

void print(int a[4][4],int c1,int c2,int move)
{
 int q,r;
 clrscr();
 printf("\n\n\n\n\n\n\n");
 printf("\t\t\t     DO YOU HAVE IT IN YOU?\n");
 printf("\t\t\t     ______________________\n\n");
 printf("\t\t\t---------------------------------\n");
 for(q=0;q<4;q++)
 {
  printf("\t\t\t|       |       |       |       |\n\t\t\t");
  for(r=0;r<4;r++)
  {
   if(q==c1&&r==c2)
    printf("|   %-c\t",c);
   else
    printf("|   %-d\t",a[q][r]);
  }
  printf("|\n\t\t\t|       |       |       |       |\n");
  printf("\t\t\t---------------------------------\n");
 }
 printf("\n\t\t\t       Number of moves=%d\n",move);
}

//=========================================================================
