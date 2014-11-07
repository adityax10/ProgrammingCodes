#include<bits/stdc++.h>
using namespace std;

int cal_dp(vector<int> &a)
{
	//dp[i] stores min jumps req to reach index i;
	vector<int> dp(a.size()+1);
	int n = a.size();
	for(int i=1;i<n;i++)
	dp[i]=INT_MAX;
	dp[0]=0;

	for( int i = 0 ; i < n ; i++ )
	{
		if( a[i] != 0 )
		{
			for( int j = i + 1 ; j <= i + a[i] && j < n ; j++)
			{
				dp[j] = min (dp[j],dp[i]+1);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[n-1];
}

int main()
{
	vector<int> a={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	cout<<cal_dp(a);
	return 0;
}


