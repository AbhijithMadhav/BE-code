#include<iostream.h>
#include<conio.h>
int w[100],p[100],n;
int max(int a,int b)
{
 if(a>b)
  return a;
 else
  return b;
}

int f(int i,int y)
{
 if(i==n)
  return(w[i]<y?p[i]:0);
 if(w[i]<=y)
  return(max(f(i+1,y),f(i+1,y-w[i])+p[i]));
 else
  return(f(i+1,y));
}

void main()
{
 int os,y;
 cout<<"Enter the number of objects\n";
 cin>>n;
 cout<<"Enter the capacity of the knapsack\n";
 cin>>y;
 for(int i=1;i<=n;i++)
 {
  cout<<i<<":weight=";
  cin>>w[i];
  cout<<"  profit=";
  cin>>p[i];
 }
 os=f(1,y);
 cout<<"Optimal solution="<<os<<endl;
 getch();
}