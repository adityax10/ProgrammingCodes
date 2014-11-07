#include <bits/stdc++.h>

using namespace std;

int ans(vector < vector<char> > a,int n,int m)
{
	int dp[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == 'X')
			dp[i][j] = 0;
			else 
			dp[i][j]=1;
		}
	}
	int s = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(dp[i][j]==1)
			dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
			else
			dp[i][j] = 0;
			s = max(s,dp[i][j]);
		}
	}
	return s;
}


int main(int argc, char** argv) {
	int n,m,k,x,y;
	vector < vector<char> > a( n, vector<char> (m));  
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>a[i][j];
	}
	while(k--)
	{
		cin>>x>>y;
		a[x-1][y-1]='X';
		cout<<ans(a,n,m)<<endl;
	}
	return 0;
}

