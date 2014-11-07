#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<unsigned long long ,unsigned long long > ans;

vector<int> v; 
int index[200001];

int main()
{
	int n,b,q;
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		index[v[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		index[i+1]+=index[i];
	}
	cin>>q;
	while(q--)
	{
		int y;
		cin>>y;
		cout<<index[y];
	}
	return 0;
}

