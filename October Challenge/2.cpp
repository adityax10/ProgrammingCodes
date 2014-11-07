#include<iostream>
#include<cmath>
using namespace std;

long long n;

void check_lucky(long long num)
{
	int x;
	while(num)
	{
		x=num%10;
		if(x==4 || x== 7)
		n++;
		num/=10;
	}
}

int main()
{
	long long  x;
	int cases;
	long long i;
	
	cin>>cases;
	while(cases)
	{
		cin>>x;
		n=0;
		for(i=2;i<sqrt(x);i++)
		{
			if(x%i==0)
			{
			  check_lucky(i);
			  check_lucky(x/i);	
			}
		}
		if(i==sqrt(x))
		{
			check_lucky(i);
			n++;
		}
		check_lucky(x);
		
		cout<<n<<"\n";
		cases--;
	}
	return 0;
}
