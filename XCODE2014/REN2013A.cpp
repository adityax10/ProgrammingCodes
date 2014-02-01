#include<iostream>
using namespace std;

int pow(int a,int n)
{
	int x=1,y=a;
	while(n)
	{
		if(n%2==1)
		{
			x = x*y; 
		}
		y = y*y;
		n = n/2;
	}
	return x;
}

int find_base(int n)
{
	int base=0,x;
	while(n)
	{
		x = n%10;
		n = n/10;
		base = max(base,x);
	}
	return base+1;
}

long long int convert(int n,int base)
{
	long long int num = 0,i=0 ;
	while(n)
	{
		num += (n%10)*pow(base,i);
		n = n/10;
		i++;
	}
	return num;
}

int main()
{
	int cases;
	int x,y;
	cin>>cases;
	while(cases--)
	{
		cin>>x>>y;
		int b1 = find_base(x);
		int b2 = find_base(y);
		cout<<convert(x,b1)+convert(y,b2)<<endl;
	}


	return 0;
}


