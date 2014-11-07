#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[],int dp[],int l,int r,int key)
{
	int mid;
	int n=r;
	while(r>=l)
	{
		 mid = (l+r)/2;
		
		if(a[dp[mid]] < key)
		{
			l=mid+1;
		}
		else if(a[dp[mid]] > key)
		{
			r = mid-1;
		}
		if(mid==0 && a[dp[mid]]>key  && a[dp[mid+1]] > key)
		return mid;
		else if(mid==n && a[dp[mid]]>key && a[dp[mid-1]]<key )
		return mid;
		if(a[dp[mid]]>key && a[dp[mid-1]]<key && a[dp[mid+1]] > key )
		return mid;
	}
	
}

int cal_dp(int a[],int n)
{
	int dp[n];// stores the last indexes of the various LIS
	int indexes[n];
	int sequenece[n];
	int len;
	//nlog(n)
	dp[0]=0;
	sequenece[0]=-1;
	len=1;
	
	for(int i=1;i<n;i++)
	{
		//new starting element for dp[]
		if(a[i] < a[dp[0]])
		{
			dp[i]=i;
		}
		//extend the sequence
		else if(a[i] > a[dp[len-1]] ) // len-1 cuz len is initailisedto 1
		{
			dp[len]=i;
			sequenece[i] = dp[len-1];
			len++;
		}
		//replace element in between..
		// find the index to replace using binary search
		else
		{
			int replace_pos = bin_search(a,dp,0,len-1,a[i]);
			dp[replace_pos] = i;
			sequenece[i] = dp[replace_pos-1];
		}
		cout<<dp[i]<<" "<<sequenece[i]<<" , ";
	}
	cout<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<sequenece[i]<<" ";
	}
	cout<<endl;
	for(int i=dp[len-1];i>=0;i=sequenece[i])
	{
		cout<<i<<" "<<a[i]<<" , ";
	}
	cout<<endl;
	
	return len;
}

int main()
{
	int a[] = { 2 , 7 , 10 , 1 , 5 , 6 , 8 };
	//int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	cout<<cal_dp(a,sizeof(a)/sizeof(int));
	return 0;
}


