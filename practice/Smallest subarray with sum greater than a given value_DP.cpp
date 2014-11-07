#include <bits/stdc++.h>

using namespace std;

int cal_dp(int a[],int n,int s)
{
	int dp[s+1][n];
	// sum > s possible using dp[s][n] terms from 1...n terms
	for(int i=0;i<n;i++)
	dp[0][i]=1;
	
	// DP
	for(int i=1;i<=s;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				dp[i][0] = a[0]>i;
				continue;
			}
			dp[i][j] = dp[i][j-1];
			if(i-a[j] >= 0)			
			dp[i][j] = min( dp[i][j] , dp[i-a[j]][j-1] )+1;
		}
	}
	return dp[s][n-1];
}

 
 
int main(int argc, char** argv) {
	int a[]= {1,4,45,6,3};
	int s = 51;
	cout<<cal_dp(a,sizeof(a)/sizeof(int),s);
	return 0;
}

