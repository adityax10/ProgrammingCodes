#include<bits/stdc++.h>
using namespace std;

/*
this is biotonic
  |
  ||
 ||||
||||||
->|<--
inc|dec
*/

int cal_dp(int a[],int n)
{
	//using the logic of longest common subsequence
	int lis[n];
	int lds[n];
	
	for(int i=0;i<n;i++)
	{
		lis[i]=1;
		lds[i]=1;
	}
	// longest inc seq from left to right	<---i
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i] && lis[j]+1 > lis[i])
			lis[i] = lis[j] +1;
		}
	}
	//display
	for(int i=0;i<n;i++)
	{
		cout<<lis[i]<<" ";
	}
	cout<<endl;
	//longest inc seq from right to left i--->
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n;j>i;j--)
		{
			if(a[i]>a[j] && lds[j]+1 > lds[j])
			lds[i] = lds[j]+1;
		}
	}	
	//display
	for(int i=0;i<n;i++)
	{
		cout<<lds[i]<<" ";
	}
	cout<<endl;
	// finding i that max lis[i] n lds[i]  <----i--->
	int ans = -1;
	for(int i=0;i<n;i++)
	{
		ans = max(ans,lis[i]+lds[i]-1);
	}
	return ans;
}

int main()
{
	int a[]={1,11,2,10,4,5,2,1};
	cout<<cal_dp(a,sizeof(a)/sizeof(int));
	return 0;
}


