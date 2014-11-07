/*
You are given n pairs of numbers.
In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
Find the longest chain which can be formed from a given set of pairs.
For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
then the longest chain that can be formed is of length 3,
and the chain is {{5, 24}, {27, 40}, {50, 90}}
*/

#include<bits/stdc++.h>
using namespace std;
#define SIZE 2000

int cal_dp(pair<int,int> p[],int n)
{
	int dp[n+1];
	dp[0]=1;
	for(int i=1;i<n;i++)
	dp[i]=-1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(p[j].second  < p[i].first)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
}

int main()
{
	pair<int,int> p[SIZE];
	int n=6;
	int a[] = {5,39,15,27,50};
	int b[] = {24,60,18,40,90};
	
	for(int i=0;i<n;i++)
	{
		p[i].first = a[i];
		p[i].second = b[i];
	}
	
	cout<<cal_dp(p,n);

	return 0;
}


