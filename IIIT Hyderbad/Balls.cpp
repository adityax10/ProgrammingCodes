#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> l_f;
map<int,int> r_f;
vector<int> mth;
bool inserted[100000];

int main()
{
	int n;
	cin>>n;
	int i=n;
	int a,b;
	if(n%2==1)
	n++;
	while(i--)
	{
		cin>>a>>b;
		l_f[a]++;
		r_f[b]++;
		if(l_f[a]+r_f[a]>=n/2 && !inserted[a])
		{
			mth.push_back(a);
			inserted[a]=1;
		//	cout<<"I 1:"<<a<<endl;
		}
		if(l_f[b]+r_f[b]>=n/2 && !inserted[b])
		{
			mth.push_back(b);
	     	inserted[b]=1;
		//	cout<<"I 2:"<<b<<endl;
		}
		//cout<<"l_f "<<a<<l_f[a]<<" "<<"r_f "<<b<<r_f[b]<<endl;
	}
	
	if(mth.size()==0)
	{
		cout<<"Impossible\n";
	}
	else
	{
		int min_diff = INT_MAX;
		for(int i=0;i<mth.size();i++)
		{
			if(l_f[mth[i]]>=n/2)
			min_diff = 0;
			else
			min_diff= min(min_diff, r_f[mth[i]]);
		}
		if(min_diff==INT_MAX)
		cout<<"0\n";
		else
		cout<<min_diff<<endl;
	}
	return 0;
}


