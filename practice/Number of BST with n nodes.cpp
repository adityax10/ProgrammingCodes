#include<bits/stdc++.h>
using namespace std;

// o(n^2)
int cal_dp(int n)
{
	int dp[n];
	dp[0]=1;
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=i;j++)
		{
			int l = j-1; // to left of i
			int r = i-j; // to right of i
			if(l==1)
			{
				dp[i] += dp[r];
			}
			else if(r == i)
			{
				dp[i] += dp[l];
			}
			else
			dp[i] += dp[l]*dp[r];
		}
	}
	return dp[n];
}

int main()
{
	cout<<cal_dp(4);
	return 0;
}


