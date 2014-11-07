#include<bits/stdc++.h>
using namespace std;
/*
Given an array of n positive integers.
 Write a program to find the sum of maximum sum subsequence of the given array such that
  the intgers in the subsequence are sorted in increasing order.
  For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
  if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) 
  and if the input array is {10, 5, 4, 3}, then output should be 10 
*/

int cal_dp(int a[],int n)
{
	int dp[n+1];
	// initialise
	for(int i=0;i<n;i++)
	dp[i]=INT_MIN; // max sum incresing subsequence found uptill i.
	dp[0]=a[0];
	int ans = a[0];
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j] <= a[i])
			dp[i] = max(a[i]+dp[j],dp[i]);
		}
		ans = max(ans,dp[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return ans;
}

int main()
{
	int arr[]={1,101,2,3,100,4,5};
	
	cout<<cal_dp(arr,sizeof(arr)/sizeof(int));

	return 0;
}


