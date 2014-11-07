#include <bits/stdc++.h>

using namespace std;

bool dp[101][101][101];

int cal()
{
	//0 => ashima
	//1 => ashwariya
	dp[0][0][0]=1;
	
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int k=0;k<=100;k++)
			{
				// doing one step
				if( 
				(k-1 >=0 && dp[i][j][k-1]!=0) ||
				(j-1 >=0 && dp[i][j-1][k]!=0) ||
				(i-1 >=0 && dp[i-1][j][k]!=0) ||
				(j-1>=0 && k-1>=0 &&  dp[i][j-1][k-1]!=0) ||
				(i-1>=0 && k-1 >=0 && dp[i-1][j][k-1]!=0) ||
				(i-1>=0 && j-1>=0 && dp[i-1][j-1][k]!=0 )||
				( i-1>=0 && j-1>=0 && k-1>=0 && dp[i-1][j-1][k-1]!=0)
				)
				{
					dp[i][j][k] = 0;
				}
				else
				dp[i][j][k] = 1;
			}
		}
	}
	return 0;
}

int main(int argc, char** argv) {
	int n;
	cal();
	cin>>n;
	while(n--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(dp[x][y][z]==0)
			cout<<"Ashima\n";
		else
			cout<<"Aishwarya\n";
	}
	return 0;
}

