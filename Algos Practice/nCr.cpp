#include<bits/stdc++.h>
using namespace std;

int cal_nCr(int n,int r)
{
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][i]=1;
		dp[i][0]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i-1>=j)
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //nCr = n-1 C r-1 + n-1 C r
			else
			dp[i][j] = dp[i-1][j-1];
		}
	}
	return dp[n][r];	
}

int main()
{
	int n = 5;
	int r = 2;
	cout<<cal_nCr(n,r);
	return 0;
}


