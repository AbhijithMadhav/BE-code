#include<iostream.h>
#include<conio.h>
#include<string.h>
class string
{
 char *a;
 public:
 string(char *b)
 {
  a=new char[strlen(b)+1];
  strcpy(a,b);
 }
 string(){}
 string(string &s)
 {
  cout<<"IN COPY CONSTRUCTOR\n";
  a=new char[strlen(s.a)+1];
  strcpy(a,s.a);
 }
 string operator +(string s)
 {
  string s3;
  s3.a=new char[strlen(a)+strlen(s.a)+1];
  strcpy(s3.a,a);
  strcat(s3.a,s.a);
  return s3;
 }
 void display()
 {
  cout<<a;
 }
};

void main()
{ string s1="VTU",s2="BELGAUM";
 string s3=s1+s2;
 s3.display();
 getch();
}


