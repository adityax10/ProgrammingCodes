
/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string.
For example, minimum 3 cuts are needed for “ababbbabbababa”. 
The three cuts are “a|babbbab|b|ababa”. 
If a string is palindrome, then minimum 0 cuts are needed.
If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/

#include<bits/stdc++.h>
using namespace std;

int cal_dp(string &s)
{
	int n = s.size();
	bool dp[n][n]; //denotes if str[i..j] is a pallindrome ar not..
	int cost[n][n]; //  denotes the min cost required for making partitioned pallindrome string between s[i..j]; 
	
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
		cost[i][i]=0;
	}
	
	//same as in matrix multiplication
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l+1;i++)
		{
			int j = l+i-1;
			
			//checking for pallindrome
			if(l==2)
			{
				dp[i][j] = (s[i]==s[j]);
			}
			else
			{
				dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
			}
			// calculating the cost
			if(dp[i][j])
			cost[i][j]=0;
			else
			{
				// assume the max cost for making s[i..j] partitioned into a paliindrome..
				cost[i][j]=j-i;
				// now reduce it
				for(int k=i+1;k<j;k++)
				cost[i][j] = min (cost[i][j],cost[i][k]+cost[k+1][j] + 1); // +1 cuz we have [i..k] | [k+1 ... j]
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		cout<<cost[i][j]<<" ";
		cout<<endl;
	}
	return cost[0][n-1];
}

int main()
{
	//string s = "ababbbabbababa";
	//string s = "abbacdcef"; 
	string s = "ababa";
	cout<<cal_dp(s);
	return 0;
}


