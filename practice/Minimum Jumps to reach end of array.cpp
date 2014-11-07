#include<bits/stdc++.h>
using namespace std;

int cal_dp(int a[],int n)
{
	int dp[n+1]; // minimum jumps to eacjh ith pos
	dp[0]=0;
	for(int i=1;i<n;i++)
	dp[i]=INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=i+a[i] && j<n;j++)
		{
			dp[j] = min(dp[j],dp[i]+1);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<endl;
	}
	cout<<endl;
	return dp[n-1];
}

int main()
{
	//int a[]={1, 3, 6, 1, 0, 9};
	int a[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	cout<<cal_dp(a,sizeof(a)/sizeof(int));

	return 0;
}


