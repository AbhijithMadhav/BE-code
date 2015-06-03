#include<iostream.h>
#include<conio.h>

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int partition(int pivot,int low,int high,int a[])
{
	int i=low,j=high;
	while(1)
	{
		while(a[i]<=pivot&&i<high)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(a[i],a[j]);
		else
			return j;
	}
}

void main()
{
	int n,a[100];
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		int j=partition(a[i],0,n-1,a);
		swap(a[i],a[j]);
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<"  ";
	getch();
}