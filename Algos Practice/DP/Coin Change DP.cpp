#include<bits/stdc++.h>
using namespace std;

int ways_to_change(int x,int c[],int n)
{
	// dp[x][j] denotes ways to make x from [0..j] th coin denominations
	int dp[x+1][n+1];
	
	for(int i=0;i<=n;i++)
	{
		dp[0][i] = 0; 
	}
	
	dp[c[0]][0]=1;
	
	for(int i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j] =  (i-c[j]) < 0 ? 0 : dp[i-c[j]][j] + (j-1) < 0 ? 0 : dp[i][j-1];
		}
	}
	
}

int main()
{
	int c[]={1,2,3,4};
	int x = 4;
	cout<<ways_to_change(x,c,sizeof(c)/sizeof(int)-1);
	return 0;
}
