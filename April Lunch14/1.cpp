#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector<int> a;

int main()
{
	int cases;
	ios_base::sync_with_stdio(false);
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		a.resize(n);
		int m=INT_MIN;
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		m = max(m,a[i]);
		}
		
		for(int num=2;num<=m;num++)
		{
			for(int i=0;i<n;i++)
			{
				if((a[i]%num)==0)
				{
				cout<<"D : "<<a[i]<<endl;
				
				a[i]/=num;
				}
			}
		}
		long long int product=1;
		for(int i=0;i<n;i++)
		{
			product *= a[i];
			product = product%1000000007;
		}
		cout<<product<<endl;
	}


	return 0;
}


