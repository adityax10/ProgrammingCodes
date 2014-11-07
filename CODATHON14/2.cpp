#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

long long a[101][101];
long long dp[101][101];
long long path[101][101];
	
int cal_dp(int n,int c)
{
	path[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			dp[0][0] = a[0][0];
			
			else if(i==0)
			{
				dp[i][j] = (dp[i][j-1] + a[i][j]) % MOD;
				path[i][j] = path[i][j-1];
			}
			
			else if(j==0)
			{
				dp[i][j] = (dp[i-1][j] + a[i][j])% MOD;	
				path[i][j] = path[i-1][j];
			}
			else
			{
				if(dp[i-1][j] > dp[i][j-1])
				{
				dp[i][j] = (dp[i-1][j] + a[i][j])%MOD;
				path[i][j] = path[i-1][j];
				}
				else if(dp[i-1][j] < dp[i][j-1])
				{
				dp[i][j] = (dp[i][j-1] + a[i][j])%MOD;
				path[i][j] = path[i][j-1];
				}
				else
				{
				dp[i][j] =( dp[i][j-1] + a[i][j] )%MOD;
				path[i][j]=(path[i][j-1]+path[i-1][j])%MOD;
				}
			}
		}
	}
	

	if(dp[n-1][n-1] > c)
	{
		cout<<"YES\n";
		cout<<dp[n-1][n-1]<<" "<<path[n-1][n-1]<<endl;
	}
	else
	cout<<"NO\n";
	return 0;
}

int main(int argc, char** argv) {
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cal_dp(n,c);
	
	return 0;
}

