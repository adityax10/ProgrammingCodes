#include<iostream>

using namespace std;

unsigned long long saved_val[100000000];

unsigned long long compute_pow(int x,unsigned long n)
{
	if(n==1)
	return x;
	else if(n==0)
	return 1;
	if(saved_val[n]!=0)
	return saved_val[n];
	saved_val[n] = (compute_pow(x,n/2)*compute_pow(x,n-n/2))%1000000009;
	return saved_val[n];
}

int main()
{
	unsigned long n;
	unsigned long long ans;
	int cases;
	
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		ans = compute_pow(2,n);
		ans--;
		cout<<ans<<"\n";
	}
	return 0;
}
