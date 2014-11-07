#include<bits/stdc++.h>
using namespace std;

//leetcode.com

int partition(int a[],int n,int k)
{
	int sum_upto[n+1];
	sum_upto[0]=a[0];
	for(int i=1;i<=n;i++)
	{
		sum_upto[i] = sum_upto[i-1] + a[i];
	}
	
	// dp[i][j] denotes the minimum of the maximum sum over the j partions IN [0...i] terms
	int dp[n+1][k+1];
	
	for(int i=0;i<=n;i++)
	dp[i][1]=sum_upto[i];
	
	for(int i=0;i<=k;i++)
	dp[0][i]=a[0];
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			dp[i][j] = INT_MAX;
			for(int z=1;z<=i;z++)
			{
				dp[i][j] = min ( dp[i][j] , max( dp[i-z][j-1] , sum_upto[i] - sum_upto[i-z] ));
				cout<<dp[i][j]<<endl;
			}
			int x;
			cin>>x;
			cout<<"dp["<<i<<"]["<<j<<"] "<<dp[i][j]<<endl;
		}
	}
	return dp[n][k];	
}

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int n=9,k=2;
	cout<<partition(a,n,k);
	return 0;
}
