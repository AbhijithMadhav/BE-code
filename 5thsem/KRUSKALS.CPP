#include<iostream.h>
#include<conio.h>
#define NOEDGE 30000

int s[100][100],reach[100];

class graph
{
 int vertices,a[100][100];
 public:
 void create(int);
 void add(int,int,int);
 void bfs(int);
 int check(int,int);
 int kruskals();
 void min(int&,int&);
};

void graph::create(int n)
{
 vertices=n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   a[i][j]=NOEDGE;
}

void graph::add(int i,int j,int w)
{
 a[i][j]=a[j][i]=w;
}

void graph::bfs(int i)
{
 for(int j=1;j<=vertices;j++)
  reach[j]=0;
 int st[100],top=-1;
 st[++top]=i;
 reach[i]=1;//**************************
 while(top!=-1)
 {
  j=st[top--];
  for(int w=1;w<=vertices;w++)
   if(s[j][w]==1&&reach[w]!=1)
   {
    reach[w]=1;
    st[++top]=w;
   }
 }
}

int graph::check(int i,int j)
{
 bfs(i);
 if(reach[j]==1)
  return 0;
 else
  return 1;
}

void graph::min(int &i,int& j)
{
 int min=NOEDGE;
 for(int u=1;u<=vertices;u++)
  for(int v=1;v<=vertices;v++)
   if(a[u][v]<min)
   {
    min=a[u][v];
    i=u;
    j=v;
   }
}

int graph::kruskals()
{
 int i,j,edges=0,cost=0;
 while(edges!=vertices-1)
 {
  min(i,j);
  if(check(i,j))
  {
   s[i][j]=s[j][i]=1;
   edges++;
   cost+=a[i][j];
   a[i][j]=a[j][i]=NOEDGE;
  }
  else
   a[i][j]=a[j][i]=NOEDGE;
 }
 return cost;
}

void main()
{
 clrscr();
 int n,x,y,w,cost;
 cout<<"Enter the number of vertices\n";
 cin>>n;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   s[i][j]=0;
 graph g;
 g.create(n);
 cout<<"Enter the number of edges\n";
 cin>>n;
 cout<<"Enter the edges and thier weights\n";
 for(i=1;i<=n;i++)
 {
  cout<<"Edge:";
  cin>>x;
  cin>>y;
  cout<<"Weight:";
  cin>>w;
  g.add(x,y,w);
 }
 cost=g.kruskals();
 for(i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
   cout<<s[i][j]<<" ";
  cout<<endl;
 }
 cout<<"Cost="<<cost<<endl;
 getch();
}