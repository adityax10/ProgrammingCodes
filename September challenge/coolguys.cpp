#include<iostream>

using namespace std;

int main()
{
	int a,b,cases;
	long long n,count;
	long long  i;
	//n=1000;
	cin>>cases;
	while(cases)
	{
	cin>>n;
	count=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j)
			{
				count++;
				continue;
			}
			if( i>j && i%j==0)
			{
			count++;
		    }
		}
	}
//	int ans = __gcd(a,b) ; 
	cout<<count<<"/"<<n*n<<"\n";
	cases--;
    }
	
}
