#include<iostream.h>
#include<conio.h>
#include<string.h>

class string
{
 char a[10];
 public:
 string(char str[])
 {
  strcpy(a,str);
 }
 string operator +(string s2)
 {
  strcat(a,s2.a);
  return(*this);
 }

 friend ostream& operator <<(ostream &out,string s);
};

 ostream& operator <<(ostream &out,string s)
 {
  out<<s.a<<endl;
  return(out);
 }
/*string string::operator +(string s2)
{
 string s3;
 strcat(a,s2.a);
 strcpy(s3.a,a);
 return(s3);
}*/

void main()
{
 string s1="VTU";
 cout<<s1;
 string s2="BELGAUM";
 cout<<s2;
 s1=s1+s2;
 cout<<s1;
 getch();
}




