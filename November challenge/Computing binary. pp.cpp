#include<iostream>

using namespace std;

unsigned long long binary(int n)
{
	unsigned long long x=0;
	int i=0;
	unsigned long long k=1;
	while(n>0)
	{
		x = x + n%2 * k;
		k = k*10;
		n=n/2;
	}
	return x;
}

int main()
{
	cout<<binary(600000);
}
