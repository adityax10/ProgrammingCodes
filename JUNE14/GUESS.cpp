#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long a,b;
	long long cases;
	cin>>cases;
	while(cases--)
	{
		cin>>a>>b;
		long long num = a/2 * (b - b/2) + b/2 * (a - a/2);
		long long den = a*b;
		long long x = __gcd(num,den);
		cout<<num/x<<"/"<<den/x<<endl;
	}
	return 0;
}


