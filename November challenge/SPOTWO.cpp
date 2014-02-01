#include<iostream>
#include<map>

using namespace std;

map<unsigned long long ,unsigned long long > ans;

unsigned long long compute_pow(int x,unsigned long long n)
{
	if(n==1)
	return x;
	else if(n==0)
	return 1;
	else if(ans[n]!=0)
	return ans[n];
	ans[n] = compute_pow(x,n/2)*compute_pow(x,n-n/2)%1000000007; 
	return ans[n];
}

unsigned long long binary(long n)
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
	int n;
	unsigned long long ans,bin;
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		bin = binary(n);
		ans = compute_pow(2,bin);
		ans = (ans*ans) %1000000007;
		cout<<ans<<"\n";
	}
	return 0;
}
