#include<bits/stdc++.h>
using namespace std;

int cal_dp(int a[],int n)
{
	int dp[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		dp[i][j]=0;
	
	
	//dp[i][j] denotes the number of terms in a AP starting with a[i] and a[j] as their first 2 elements
	for(int j=n-2;j>=0;j--)
	{
		int i=j-1; // term left to j
		int k=j+1; // term right to j
		while(i>=0 && k<=n-1)
		{
			if(a[i]+a[k] > 2*a[j])
			{
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				dp[i][j] = dp[j][k]+1;
				i--;
				//ans++;
			}
			else if(a[i]+a[k] < 2*a[j])
			{
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				//ans++;
				k++;
			}
			else
			{
				
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
	return 0;
}

int main()
{
	//int arr[]={-8,-6,-4,0,1,2,3,4,5,8,10,12,15,16,20};
	int arr[] = {1,2,4,5,10};
	cout<<cal_dp(arr,sizeof(arr)/sizeof(int));
	return 0;
}


