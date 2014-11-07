#include<stdio.h>
  int fibo(int n);
int main()
{
  int i,n;
  printf("Enter the value of n for fibonacci terms...");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  printf("%d\t",fibo(i));
  }
  int fibo(int n)
{
int y;
if(n==1||n==0)
return n;
else
{
y=fibo(n-1)+fibo(n-2);
return y;
}}
