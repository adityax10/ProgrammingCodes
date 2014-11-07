#include <bits/stdc++.h>

using namespace std;

bool dp[33];
int d[33];

int cal_dp(int n)
{
	//0 - chetu
	//1 - nishu
	dp[1]=0;
	dp[2]=0;
	dp[3]=1;
	d[1]=1;
	d[2]=1;
	d[3]=2;
	for(int i=4;i<=n;i++)
	{
		if(dp[i-1]==1)
		{
		dp[i] = 0;
		d[i] = d[i-1]+1;
		}
		else if(dp[i-2]==1)
		{
		dp[i] = 0;
		d[i] = d[i-2]+1;
		}
		else
		{
			dp[i] = 1;
			d[i] = d[i-2]+1;
		}
	}
	return 0;
}

int main(int argc, char** argv) {
	
	int cases;
	cin>>cases;
	int x;
	cal_dp(32);
	while(cases--)
	{
		cin>>x;
		x= 32 - x;
		if(!dp[x])
		cout<<"CHETU ";
		else 
		cout<<"NISHU ";
		cout<<d[x]<<endl;
	}
	return 0;
}

