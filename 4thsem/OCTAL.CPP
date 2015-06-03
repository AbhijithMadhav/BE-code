#include<iostream.h>
#include<conio.h>
#include<math.h>
class octal
{
 int oct;
 public:
 octal(int);
 int operator +(int);
 void display()
 {
   cout<<oct;
  }
};

octal::octal(int x)
{
 oct =0;
 int q,i=0;
 while(x>8)
 {
  q=x%8;
  x/=8;
  oct+=(q*pow(10,i));
  i++;
 }
  oct+=(x*pow(10,i));
}
int octal::operator +(int k)
{
 int dec=0,i=0,q,n=oct;
 while(n!=0)
 {
  q=n%10;
  n/=10;
  dec=dec+(q*pow(8,i));
  i++;
 }
 return(dec+k);
}

void main()
{
 int x,k,y;
 clrscr();
 cout<<"Enter an decimal number\n";
 cin>>x;
 octal h(x);
 cout<<"Octal equivalent=";
 h.display();
 cout<<endl;
 cout<<"Enter a decimal\n";
 cin>>k;
 y=h+k;
 cout<<"sum="<<y;
 getch();
}