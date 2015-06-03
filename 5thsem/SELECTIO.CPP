#include<iostream.h>
#include<conio.h>
int a[100];

void swap(int &m,int &n)
{
 int temp=m;
 m=n;
 n=temp;
}

int selection(int l,int r,int k)
{
 int i=l+1,j=r;
 int pivot=a[l];
 while(1)
 {
  while(pivot>a[i]&&i<=r)
   i++;
  while(pivot<a[j])
   j--;
  if(i>=j)
   break;
  else
  swap(a[i],a[j]);
 }
 if(k==j-l+1)
  return pivot;
 a[l]=a[j];
 a[j]=pivot;
 if(k<j-l+1)
  return(selection(l,j-1,k));
 else
  return(selection(j+1,r,k-(j-l+1)));
}

void main()
{
 clrscr();
 int n,k;
 cout<<"Enter the number of elements\n";
 cin>>n;
 cout<<"Enter the elements\n";
 for(int i=0;i<n;i++)
  cin>>a[i];
 cout<<"Enter the position of the required element\n";
 cin>>k;
 int s;
 if(k>0&&k<n)
 {
  s=selection(0,n-1,k);
  cout<<k<<" element="<<s<<endl;
 }
 else
  cout<<"Invalid position\n";
 getch();
}


