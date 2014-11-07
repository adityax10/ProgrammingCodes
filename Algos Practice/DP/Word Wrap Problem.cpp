#include<bits/stdc++.h>
using namespace std;

int cal_min_cost(string &s,int M)
{
	vector<int> l; // denotes the length of the ith word
	// storing word lengths in a[]
	// let us say the that cost is calculated as follows
	// s = abc def
	//M=4
	//abc- // 1 space
	//def- // 1 space
	//cost = 1*1 + 1*1

	int i_prev = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		{
			l.push_back(i-i_prev);
			i_prev=i+1;
		}
		else if(i==s.size()-1)
		{
			l.push_back(i-i_prev+1);
		}
	}
	
	
	int n = l.size();
	int dp[n][n] ; // denotes the min cost of placing words from ith to jth index in a line
	int c[n]; // denotes the min cost of placing elements from 1 to ith element
	int extras[n][n] ; // denotes the spaces left after considering ith to jth words in a line of M size
	int ans[n]; // to store the answer
	
	for(int i=0;i<n;i++)
	cout<<l[i]<<" ";
	cout<<endl;
	
	// finding out the extra spaces left in line if words ith to jth are considered
	// -ve extras indicate words from i to j cant be placed in the line of length M
	for(int i=0;i<n;i++)
	{
		extras[i][i] = M - l[i];
		for(int j=i+1;j<n;j++)
		{
			extras[i][j] = extras[i][j-1] - l[j] - 1 /* for space */;
		}
	}
	//display
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			cout<<extras[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(extras[i][j]<0)
			dp[i][j] = INT_MAX;
			//else if(j==n && extras[i][j]>=0)
			//dp[i][j] = 0;
 			else
			dp[i][j] = extras[i][j] * extras[i][j];
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	c[0]=dp[0][0];
	ans[0]=-1;
	//now.. the dp
	for(int i=1;i<n;i++)
	{
		c[i]=dp[0][i];
		ans[i]=-1;
		for(int j=0;j<i;j++) //-1 cuz i wanna look into dp[0][i] diretly too for min cost
		{
			if(c[j]!=INT_MAX && dp[j+1][i]!=INT_MAX && c[i] > c[j] + dp[j+1][i] )
			{
		 	c[i] =  c[j] + dp[j+1][i]; 
		 	ans[i]=j;
		 	}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	//solution
	int i=n-1;
	while(i!=-1)
	{
		int j=ans[i]+1;
		cout<<"From word "<<j<<" to "<<i<<endl;
		i=ans[i];
	}
	
	return c[n-1];
}

int main()
{
	string s = "Geeks for Geeks presents";
//	string s = "Aditya Vats is great";
	int M=15; // LINE SIZE => M
	
	cout<<cal_min_cost(s,M);
	
	return 0;
}


