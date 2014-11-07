#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long n,k,MAX=LONG_MIN,MIN=LONG_MAX;
	cin>>n>>k;
	vector<long long> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		MAX = max(MAX,v[i]);
		MIN = min(MIN,v[i]);
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	else if(k%2==1)
	{
		for(int i=0;i<n;i++)
		{
			cout<<MAX - v[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<< v[i]-MIN<<" ";
		}
		cout<<endl;
	}
	return 0;
}

