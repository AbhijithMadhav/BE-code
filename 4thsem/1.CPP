#include<iostream.h>
#include<conio.h>

class complex
{
 int r,i;
 public:
 complex(int,int);
 complex(int);
 complex add(int,complex);
 complex add(complex,complex);
 friend ostream& operator <<(ostream&,complex);
 complex(){};
};

complex::complex(int real,int img)
{
 r=real;
 i=img;
}

complex complex::add(int real,complex s)
{
 r=real+s.r;
 i=s.i;
 return(*this);
}

complex complex::add(complex s1,complex s2)
{
 r=s1.r+s2.r;
 i=s1.i+s2.i;
 return(*this);
}

ostream& operator<<(ostream &out,complex s)
{
 out<<s.r<<"+i"<<s.i;
 return(out);
}

void main()
{
 int real,img;
 clrscr();
 cout<<"Enter the first real number\nReal part=";
 cin>>real;
 cout<<"\nImg part=";
 cin>>img;
 cout<<endl;
 complex s1(real,img);
 cout<<"Enter the second real number\nReal part=";
 cin>>real;
 cout<<"\nImg part=";
 cin>>img;
 cout<<endl;
 complex s2(real,img);
 complex s3;
 s3=s3.add(s1,s2);
 cout<<s1<<" + "<<s2<<" = "<<s3;
 cout<<"\nEnter an integer\n";
 cin>>real;
 s3=s3.add(real,s1);
 cout<<real<<" + "<<s1<<" = "<<s3;
 getch();
}