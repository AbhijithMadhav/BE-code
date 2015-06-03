#include<iostream.h>
#include<conio.h>
#define NOEDGE 300

int min(int m,int n)
{
 if(m<n)
  return m;
 else
  return n;
}

int allpairs(int i,int j,int k,int a[100][100])
{
 if(k==1||i==j)
  return a[i][j];
 else
  return(min(allpairs(i,j,k-1,a),allpairs(i,k,k-1,a)+allpairs(k,j,k-1,a)));
}

void main()
{
 int n,edges,x,y,w,p[100][100],a[100][100];
 cout<<"Enter the number of vertices\n";
 cin>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   //if(i==j)
   // a[i][j]=0;
   a[i][j]=NOEDGE;
  }

 cout<<"Enter the number of edges\n";
 cin>>edges;
 cout<<"Enter the edges and thier weights\n";
 for(i=1;i<=edges;i++)
 {
  cout<<"Edge:";
  cin>>x;
  cin>>y;
  cout<<"Weight:";
  cin>>w;
  a[x][y]=w;
 }
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   p[i][j]=allpairs(i,j,n,a);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   cout<<p[i][j]<<" ";
  cout<<endl;
 }
 getch();
}


