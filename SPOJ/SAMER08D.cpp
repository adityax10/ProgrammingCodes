#include<bits/stdc++.h>
using namespace std;

int dp(string s1,string s2,int k)
{
	vector<	vector<int> > dp(s1.size()+1,vector<int> (s2.size()+1) );
	vector<	vector<int> > s(s1.size()+1,vector<int> (s2.size()+1) );
	for(int i=0;i<=s1.size();i++)
		dp[i][0]=0;
	for(int i=1;i<=s2.size();i++)
		dp[0][i]=0;
	int ans=INT_MIN;
	// Dp
	for(int i=1;i<=s1.size();i++)
	{
		for(int j=1;j<=s2.size();j++)
		{
			if(s1[i-1]==s2[j-1])
			{
			dp[i][j] = dp[i-1][j-1] + 1;
			s[i][j] = s[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				
			}
			
		}
	}
	
	for(int i=1;i<=s1.size();i++)
	{
		for(int j=1;j<=s2.size();j++)
		{
			cout<<dp[i][j]<<" ";
		}	
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=s1.size();i++)
	{
		for(int j=1;j<=s2.size();j++)
		{
			cout<<s[i][j]<<" ";
		}	
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

int main()
{
	int n;
	freopen("insam.txt","r",stdin);
	while(cin>>n)
	{
		if(n==0)
		break;
		string s1,s2;
		cin>>s1>>s2;
		cout<<dp(s1,s2,n)<<endl;
	}
	return 0;
}


