#include<stdio.h>
#include<conio.h>
int temp=0;
gcd(n,m)
{
temp++;
if (n%m == 0)
return n;
n = n%m;
return gcd ( m, n);
}

int main()
{

 	printf("%d %d",gcd(8,9),temp);
 	//while(1)
 	getch();
}
