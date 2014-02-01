/*DP FIBONACII SERIES*/

#include<stdio.h>
#include<conio.h>
#define SIZE 100

long saved_fibo[SIZE];

long fibo(int n)
{
  if(n==0||n==1)
  return n;
  
  if(saved_fibo[n]!=0)
  return saved_fibo[n];
  else
  {
		saved_fibo[n]= fibo(n-1)+fibo(n-2);
		return saved_fibo[n];
  }
}



int main()
{
	int n,i;
	printf("Enter n : ");
	scanf("%d",&n);
	
	for(i=n-1;i>=0;i--)
	{
		printf("%ld ",fibo(i));
	}



getch();
}
