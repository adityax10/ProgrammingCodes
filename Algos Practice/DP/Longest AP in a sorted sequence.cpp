#include<bits/stdc++.h>
using namespace std;

int cal_dp(int a[],int n)
{
	int dp[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		dp[i][j]=0;
	
	for(int i=0;i<n-1;i++)
	dp[i][n-1]=2;
	
	//dp[i][j] denotes the number of terms in a AP starting with a[i] and a[j] as their first 2 elements
	int longest_ap=0;
	for(int j=n-2;j>=0;j--)
	{
		int i=j-1; // term left to j
		int k=j+1; // term right to j
		while(i>=0 && k<=n-1)
		{
			if(a[i]+a[k] > 2*a[j])
			{
				dp[i][j]=2;
				i--;
			}
			else if(a[i]+a[k] < 2*a[j])
			{
				dp[i][j]=2;
				k++;
			}
			else
			{
			   // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
				dp[i][j] = dp[j][k]+1;
				longest_ap = max(dp[i][j],longest_ap);
				i--;
				k++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>i)
			cout<<dp[i][j]<<" ";
			else
			cout<<"0 ";
		}
		cout<<endl;
	}
	return longest_ap;
}

int main()
{
	int arr[]={-8,-6,-4,0,1,2,3,4,5,8,10,12,15,16,20};
	cout<<cal_dp(arr,sizeof(arr)/sizeof(int));
	return 0;
}


