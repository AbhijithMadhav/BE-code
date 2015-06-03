#include<iostream.h>
#include<conio.h>
template<class type>
int partition(type s[],int low,int high)
{
 type key,temp;
 int i,j;
 key=s[low];
 i=low+1;
 j=high;
 while(1)
 {
  while(key>=s[i]&&i<high)
   i++;
  while(key<s[j])
   j--;
  if(j>i)
  {
   temp=s[i];
   s[i]=s[j];
   s[j]=temp;
  }
  else
  {
   temp=s[low];
   s[low]=s[j];
   s[j]=temp;
   return(j);
  }
 }
}
template<class type>
void quick_sort(type s[],int low,int high)
{
 int j;
 if(low<high)
 {
  j=partition(s,low,high);
  quick_sort(s,low,j-1);
  quick_sort(s,j+1,high);
 }
}

void main()
{
 int i,n,a[30];
 float s[30];
 clrscr();
 cout<<"Enter the number of elements in the integer array\n";
 cin>>n;
  cout<<"Enter the elements\n";
 for(i=0;i<n;i++)
  cin>>a[i];
 quick_sort(a,0,n-1);
 cout<<"The sorted integer array is\n";
 for(i=0;i<n;i++)
  cout<<a[i]<<"\t";
 cout<<endl;
 cout<<"Enter the number of elements in the double array\n";
 cin>>n;
 cout<<"Enter the elements\n";
 for(i=0;i<n;i++)
  cin>>s[i];
 quick_sort(s,0,n-1);
 cout<<"The sorted double array is\n";
 for(i=0;i<n;i++)
  cout<<s[i]<<"\t";
 getch();
}




