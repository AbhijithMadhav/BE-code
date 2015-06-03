#include<iostream.h>
#include<conio.h>
#include<string.h>
#define MAX 50
class expression
{
  char infix[100],s[100];
  int top;
  public:
  expression(char a[])
  {
   top=-1;
   strcpy(infix,a);
  }
  void in_post(char []);
  char pop();
  void push(char item);
};

int s_p(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':return(2);
  case '*':
  case '/':return(4);
  case '(':return(0);
  case '$':
  case '^':return(5);
  case '#':return(-1);
  default :return(8);
 }
}

/*------------------------------------------------------------------------*/

int i_p(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':return(1);
  case '*':
  case '/':return(3);
  case '(':return(9);
  case '$':
  case '^':return(6);
  case ')':return(0);
  default :return(7);
 }
}

/*-------------------------------------------------------------------------*/

void expression::push(char item)
{
  top=top+1;
  s[top]=item;
}

/*-------------------------------------------------------------------------*/

char expression::pop()
{
 char item;
  item=s[top];
  top=top-1;
  return(item);
}


/*--------------------------------------------------------------------------*/

void expression::in_post(char postfix[])
{
 int i,j;
 char item,symbol;
 push('#');
 j=0;
 for(i=0;i<strlen(infix);i++)
 {
  symbol=infix[i];
  while(s_p(s[top])>i_p(symbol))
  {
   postfix[j]=pop();
   j++;
  }
  if(s_p(s[top])<i_p(symbol))
   push(symbol);
  else
   pop();
 }
 while(s[top]!='#')
 {
  postfix[j]=pop();
  j++;
 }
 postfix[j]='\0';
 cout<<postfix;
}

/*------------------------------------------------------------------------*/

void main()
{
 char postfix[50],inf[50];
 clrscr();
 cout<<"Enter the infix expression\n";
 cin>>inf;
 expression s(inf);
 s.in_post(postfix);
 getch();
}
