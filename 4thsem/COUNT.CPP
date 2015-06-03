#include<iostream.h>
#include<conio.h>

template<class type>
void count(type a[],int size,int *p,int *n,int *z)
{
 for(int i=0;i<size;i++)
 {
  if(a[i]>0)
   (*p)++;
  if(a[i]<0)
   (*n)++;
  if(a[i]==0)
   (*z)++;
 }
}

void main()
{
 int pos,neg,zero,a[10],size;
 double s[10];
 pos=neg=zero=0;
 cout<<"Enter the number of elements in the integer array\n";
 cin>>size;
  cout<<"Enter the elements\n";
 for(int i=0;i<size;i++)
  cin>>a[i];
 count(a,size,&pos,&neg,&zero);
 cout<<"Positive numbers="<<pos<<endl;
 cout<<"Negative numbers="<<neg<<endl;
 cout<<"Zero's="<<zero<<endl;
 pos=neg=zero=0;
 cout<<"Enter the number of elements in the double array\n";
 cin>>size;
 cout<<"Enter the elements\n";
 for(i=0;i<size;i++)
  cin>>s[i];
 count(s,size,&pos,&neg,&zero);
 cout<<"Positive numbers="<<pos<<endl;
 cout<<"Negative numbers="<<neg<<endl;
 cout<<"Zero's="<<zero;
 getch();
}