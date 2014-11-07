#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	freopen("inmar.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<vector<int> > A(n,vector<int>(m)),B(n,vector<int>(m));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>A[i][j];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>B[i][j];
	}
	
	int dp[n+1][m+1][2];
	//0 <-
	//1 |^
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//0
			int x = ((j-1>=0)?dp[i][j-1][0]:0)+B[i][j];
			//1
			int y = ((i-1>=0)?dp[i-1][j][1]:0)+A[i][j];
			//0 is >
			if(x>y)
			{
				dp[i][j][0]=x;
			}
			else if(x==y)
			{
				dp[i][j][0]=x;
				dp[i][j][1]=y;
			}
			//1 >
			else
			{
				dp[i][j][1]=y;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dp[i][j][0]<<"/"<<dp[i][j][1]<<"  ";
		}
		cout<<endl;
	}
	
	return 0;
}


