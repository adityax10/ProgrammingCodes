#include<bits/stdc++.h>
using namespace std;

int cal_dp(string s)
{
	int n = s.size();
	bool dp[n+1][n+1]; // true if s[i..j] is a pallindrome
	
	memset(dp,0,sizeof(dp));
	int max_len = 0;
	for(int i=1;i<n;i++)
	{
		dp[i][i-1] = s[i]==s[i-1];
	}
		
	for(int d=0;d<n;d++)
	{
		for(int j=0;j+d<n;j++)
		{
			if(d==0)
				dp[j][j] = 1;
			else if(s[j]==s[j+d] && dp[j+1][j+d-1])
				dp[j][j+d] = 1;
			else
				dp[j][j+d] = 0;
				
				if(dp[j][j+d])
				max_len = max(max_len,d+1);
		}
	}	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return max_len;
}

int main()
{
	string s = "forgeekskeegforgeeksskeegrof";
	cout<<cal_dp(s);
	return 0;
}


