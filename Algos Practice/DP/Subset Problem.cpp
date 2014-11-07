#include<bits/stdc++.h>
using namespace std;

bool cal_dp(int a[],int sum,int n)
{
	bool dp[sum+1][n+1];
	
	for(int i=0;i<=n;i++)
	dp[0][i]=true;

	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				dp[i][0]= (a[0]==i);
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				if( i - a[j]  >= 0)
				{
					dp[i][j] = dp[i][j] || dp[ i - a[j] ] [ j-1 ];
				}
			}
		}
	}
	
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return dp[sum][n-1];	
}

int main()
{
	int a[]={6,3,7}; // all elements should be positive
	int n = sizeof(a)/sizeof(int);
	int m = 16;
	cout<<cal_dp(a,m,n);
	return 0;
}


