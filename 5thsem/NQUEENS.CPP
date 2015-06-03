#include<iostream.h>
#include<conio.h>

int n;
int check(int row,int col,int a[100][100])
{
 for(int i=1;i<row;i++)
  if(a[i][col]==1)
   return 0;
 int j;
 for(i=row-1,j=col-1;i>=1&&j>=1;i--,j--)
  if(a[i][j]==1)
   return 0;
 for(i=row-1,j=col+1;i>=1&&j<=n;i--,j++)
  if(a[i][j]==1)
  return 0;
 return 1;
}

void nqueens(int a[100][100])
{
 int i,j,pos[100];
 int successful;
 pos[1]=0;
 while(1)
 {
  for(int t=1;t<=n;t++)
   a[t][pos[t]]=0;
  for(t=2;t<=n;t++)
   pos[t]=0;
  i=1;
  while(i<=n)
  {
   if(pos[i]==n)
    {
     if(i==1)
     return;
     pos[i]=0;
     i--;
     a[i][pos[i]]=0;
    }
   j=pos[i]+1;
   successful=0;
   while(j<=n)
   {
    if(check(i,j,a))
    {
     successful=1;
     a[i][j]=1;
     pos[i]=j;
     break;
    }
    j++;
   }
   if(successful)
    i++;
   else
   {
    pos[i]=0;
    i--;
    a[i][pos[i]]=0;
   }
  }
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    cout<<a[i][j]<<" ";
   cout<<endl;
  }
  getch();
  cout<<endl;
  if(pos[1]==n)
  break;
 }
}


void main()
{
 clrscr();
 int a[100][100];
 cout<<"Enter the number of queens\n";
 cin>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  a[i][j]=0;
 nqueens(a);
 getch();
}