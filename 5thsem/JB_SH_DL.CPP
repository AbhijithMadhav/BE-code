#include<iostream.h>
#include<conio.h>

struct jobs
{
	int d,p;
}job[100];

int max_tslot(int n)
{
	int max=job[1].d;
	for(int i=1;i<=n;i++)
		if(max<job[i].d)
			max=job[i].d;
	return max;
}

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void bubble_sort(int n)
{
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if(job[j].p<job[j+1].p)
			{
				swap(job[j].d,job[j+1].d);
				swap(job[j].p,job[j+1].p);
			}
}

void schedule(int n)
{
	int x,t[100],profit=0;
	int m=max_tslot(n);
	for(int i=1;i<=m;i++)
		t[i]=0;
	bubble_sort(n);
	for(i=1;i<=n;i++)
	{
		x=job[i].d;
		for(int j=x;j>=1;j--)
		{
			if(t[j]==0)
			{
				t[j]=i;
				profit+=job[i].p;
				break;
			}
		}
	}
	cout<<"Profit="<<profit<<endl;
	cout<<"Scheduling order:"<<endl;
	cout<<"Time  Profit  Deadline\n";
	for(i=1;i<=m;i++)
		if(t[i]!=0)
			cout<<i<<"     "<<job[t[i]].p<<"      "<<job[t[i]].d<<endl;
}

void main()
{
	//clrscr();
	int n;
	cout<<"Enter the number of jobs\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":Profit=";
		cin>>job[i].p;
		cout<<"  Deadline=";
		cin>>job[i].d;
	}
	schedule(n);
	getch();
}






