#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

long long int d[1000];

int main()
{
	long long int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		long long int x,y,deb;
		cin>>x>>y;  // y gives x
		cin>>deb;
		d[x]+= deb;
		d[y]+= -deb;
	}
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans += (d[i]>0)?d[i]:0;
	}
	cout<<ans<<endl;


	return 0;
}


