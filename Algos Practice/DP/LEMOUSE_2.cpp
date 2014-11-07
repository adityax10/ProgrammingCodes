#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define REDIRECT_IO

int mouse[101][101];
int shadow[101][101];

int cal_ans(int n,int m)
{
	int dp[101][101][2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mouse[i][j])
			{
			if(i-1>=0)
			shadow[i-1][j]++;
			if(j+1<m)
			shadow[i][j+1]++;
			if(i+1<n)
			shadow[i+1][j]++;
			if(j-1>=0)
			shadow[i][j-1]++;
		   }
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cout<<shadow[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	dp[0][0][0]=dp[0][0][1]=shadow[0][0]-mouse[0][0];
	// 0 left
	// top
	
	for(int j=1;j<m;j++)
	{
		dp[0][j][0] = shadow[0][j] -  mouse[0][j] +dp[0][j-1][0];
		dp[0][j][1] = INT_MAX - 100000;
		cout<<dp[0][j][0]<<" ";
	}
	cout<<endl;
	for(int i=1;i<n;i++) 	
	{
		dp[i][0][1] = shadow[i][0] -  mouse[i][0] +dp[i-1][0][1];
		dp[i][0][0] = INT_MAX - 100000;
	}
	
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			dp[i][j][0] = shadow[i][j] - mouse[i][j] + min( dp[i][j-1][0], dp[i][j-1][1]-mouse[i-1][j] ); 
			dp[i][j][1] = shadow[i][j] - mouse[i][j] + min( dp[i-1][j][1], dp[i-1][j][0]-mouse[i][j-1] );    
		}
	}
	
	return min(dp[n-1][m-1][0],dp[n-1][m-1][1]) + mouse[0][0] + mouse[n-1][m-1];
}

int main()
{
	#ifdef REDIRECT_IO
	freopen("input.txt","r",stdin);
	#endif
	int cases;
	string s;
//	scanf("%d",&cases);
	cin>>cases;
	while(cases--)
	{
		int n,m;
		//scanf("%d",&n);
		//scanf("%d",&m);
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
			{
			mouse[i][j]=s[j]-48;
		    }   
			//scanf("%d",&maze[i][j]);
		}
		printf("%d\n",cal_ans(n,m));
	}
	return 0;
}


