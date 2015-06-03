void main()
{
 int n,i,j;
 printf("Enter the number\n");
 scanf("%d",&n);
 for(i=n;i>=1;i--)
 {
  j=0;
  while(j!=i)
  {
   printf("%2d ",i);
   j++;
  }
  printf("\n");
 }
 getch();
}