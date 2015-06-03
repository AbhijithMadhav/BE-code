#include<iostream.h>
#include<conio.h>
#include<string.h>

struct node
{
 int info;
 struct node *r,*l;
};
typedef struct node node;


class tree
{
 node *root;
 public:
 void create(int);
 void preorder(node*);
 void postorder(node*);
 void inorder(node*);
 void display();
 void create_dir(int,char[]);
 tree()
 {
  root=NULL;
 }
};




void tree::create(int item)
{
 node *temp,*cur,*prev;
 temp=new node;
 temp->info=item;
 temp->l=temp->r=NULL;
 if(root==NULL)
 {
  root=temp;
  return;
 }
 cur=root;
 while(cur!=NULL)
 {
  prev=cur;
  cur=(item<cur->info)?cur->l:cur->r;
 }
 if(item<prev->info)
  prev->l=temp;
 else
  prev->r=temp;
}

void tree::create_dir(int item,char a[])
{
 node *temp,*cur,*prev;
 temp=new node;
 temp->info=item;
 temp->r=temp->l=NULL;
 if(root==NULL)
 {
  root=temp;
  return;
 }
 cur=root;
 for(int i=0;a[i]!='\0';i++)
 {
  prev=cur;
  cur=(a[i]=='l')?cur->l:cur->r;
  if(prev==NULL)
  {
  cout<<"Invalid direction\n";
  return;
 }

 }
 if(cur!=NULL)
 {
  cout<<"Invalid direction\n";
  return;
 }
 if(a[strlen(a)-1]=='l')
  prev->l=temp;
 else
  prev->r=temp;
}


void tree::preorder(node *root)
{
 if(root!=NULL)
 {
  cout<<root->info<<"\t";
  preorder(root->l);
  preorder(root->r);
 }
}


void tree::postorder(node *root)
{
 if(root!=NULL)
 {
  postorder(root->l);
  postorder(root->r);
  cout<<root->info<<"\t";
 }
}


void tree::inorder(node *root)
{
 if(root!=NULL)
 {
  inorder(root->l);
  cout<<root->info<<"\t";
  inorder(root->r);
 }
}
void tree::display()
{
 preorder(root);
 cout<<endl;
 postorder(root);
  cout<<endl;
 inorder(root);
}

void main()
{
 tree s1;
 clrscr();
 int item;
 /*for(int i=1;i<=7;i++)
 {
  cin>>item;
  s1.create(item);
 }
 s1.display();*/
 tree s2;
 char a[123];
 for(int j=0;j<3;j++)
 {
  cin>>item;
  cin>>a;
  s2.create_dir(item,a);
 }
 s2.display();
 getch();
}