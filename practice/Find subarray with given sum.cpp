#include<bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.
*/

pair<int,int> cal_dp(int a[],int s,int n)
{
	int sum[n+1];
	sum[0]=a[0];
	int x=0;
	bool f=0;
	pair<int,int> p;
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(sum[i]>=s && !f)
		{
			x=i;
			f=1;
		}
		
		if(sum[i]==s)
		{
			p.first = 0;
			p.second = i;
			return p;
		}
	}
	cout<<"x "<<x<<endl;
	int start = 0;
	for(int end=x;end<n;end++)
	{
		while((sum[end]-sum[start] > s))
		{
			start++;
		}
		
		if(sum[end]-sum[start] == s)
		{
			p.first = start+1;
			p.second = end;
			return p;
		}
	}
	return make_pair(-1,-1);
}

int main()
{
	//int a[]={1, 4, 20, 3, 10, 5};
	//int s = 33;
	int a[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int s = 23;
	pair<int,int> x = cal_dp(a,s,sizeof(a)/sizeof(int));
	if(x.first!=-1)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}
	else
	{
		cout<<"Not Possible";
	}

	return 0;
}


