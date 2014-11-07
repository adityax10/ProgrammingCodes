#include<bits/stdc++.h>
using namespace std;

/*
Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].
*/

int cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first == b.first)
	return a.second<b.second;
	
	return a.first < b.first;
}

int main()
{
	// O(nlog(n))
	vector< pair<int,int> > v;
	int a[] = {4,5,2,1,3,2,3};
	int n = sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		v.push_back(make_pair(a[i],i));
	}
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	
	int min_index = v[0].second;
	int max_diff = 0;
	for(int i=1;i<n;i++)
	{
		min_index = min ( min_index , v[i].second);
		max_diff = max ( max_diff, v[i].second - min_index  );
	}
	cout<<max_diff<<endl;
	return 0;
}


