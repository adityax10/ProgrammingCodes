#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define lli long long int

vector<lli> v;

int ans=0;

int sos(int i,int sum,int m)
{
	if(i>=v.size())
	return 0;
	
	if(!(sum%m))
	{
		cout<<"Sum = "<<sum<<endl;
		ans++;
	}
	
	sos(i+1,sum+v[i],m);
	sos(i+1,sum,m);
}

int main()
{
	int t;
	int n,m;
	int q;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>n>>q;
		while(n--)
		{
			cin>>x;
			v.push_back(x);
		}
		while(q--)
		{
			cin>>m;
			ans=0;
			sos(0,0,m);
			cout<<ans<<endl;
		}
		
	}
	

	return 0;
}


