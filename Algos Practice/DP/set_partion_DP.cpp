#include<bits/stdc++.h>
using namespace std;

bool cal_set_partition(int a[],int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	sum+=a[i];
	if(sum%2)
	return 0;
	
	int dp[sum/2 + 1][n];
	// dp[x][i] denotes if the sum x can be formerd using the terms [0... i]
	
	for(int i=0;i<=n;i++)
	dp[0][i]=1;
	for(int i=1;i<=sum/2;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(j==0)
			dp[i][0] = (a[0]==i);
			else
			{
				dp[i][j] = dp[i][j-1];
				if(i - a[j] >=0)
				dp[i][j] = dp[i][j] || dp[i-a[j]][j-1];
			}
		}
	}
	return dp[sum/2][n-1];
}

int main()
{
	int a[]={1,5,11,5,2};
	cout<<cal_set_partition(a,sizeof(a)/sizeof(int));
	return 0;
}


