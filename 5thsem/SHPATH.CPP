#include<iostream.h>
#include<conio.h>
#define NOEDGE 30000
#define DELETED -1
class digraph
{
 int a[10][10],vertices;
 public:
 void shpath(int);
 digraph(int n)
 {
  vertices=n;
  for(int i=1;i<=vertices;i++)
   for(int j=1;j<=vertices;j++)
    a[i][j]=NOEDGE;
 }
 void add(int,int,int);
};

int empty(int l[],int j)
{
 for(int i=0;i<j;i++)
  if(l[i]!=DELETED)
   return 0;
  return 1;
}

void output(int s,int p[],int i)
{
int y=p[i];
	while(1)
	{
	 cout<<y<<" ";
	 if(y==s)
		return;
	 int x=p[y];
	 y=x;
	 }
}
void digraph::shpath(int s)
{
 int d[10],l[10],p[10],j=0;
 for(int i=1;i<=vertices;i++)
 {
  d[i]=a[s][i];
  p[i]=0;
  if(a[s][i]!=NOEDGE)
  {
   l[j++]=i;
   p[i]=s;
  }
 }
 while(!empty(l,j))
 {
  int minpos=1;
  for(i=0;i<j;i++)
   if(d[l[i]]<d[l[minpos]] && l[i]!=DELETED)
    minpos=i;
  int w=l[minpos];
  l[minpos]=DELETED;
  for(i=1;i<=vertices;i++) //i represents the unreached vertices
  {
   if(a[w][i]!=NOEDGE)
    if(d[i]>d[w]+a[w][i])
    { p[i]=w;
     d[i]=d[w]+a[w][i];
     int present=0;
     for(int k=0;k<j;k++)
      if(i==l[k])
       present=1;
     if(present==0)
      l[j++]=i;
    }
  }
 }
 for(i=1;i<=vertices;i++)
  cout<<i<<"\t"<<d[i]<<"\t"<<p[i]<<"\n";
	for(i=2;i<=vertices;i++)
  {
   output(1,p,i);
	 cout<<endl;
	 }
}


void digraph::add(int i,int j,int w)
{
 a[i][j]=w;
}


void main()
{
 int n;
 cout<<"Enter the no. of vertices\n";
 cin>>n;
 digraph g(n);
 cout<<"Enter the number of edges\n";
 cin>>n;
 cout<<"Enter the edges and thier wieghts\n";
 int i,j,w;
 for(int k=0;k<n;k++)
 {
  cin>>i>>j>>w;
  g.add(i,j,w);
 }
 g.shpath(1);
 getch();
}