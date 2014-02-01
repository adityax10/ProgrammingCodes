#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int lis(int a[],int n)
{
	int max_lenght[n]; // max incresing length including elemet a[i] upto i
	
	for(int i=0;i<n;i++)
	max_lenght[i]=1;
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j] < a[i] && max_lenght[i] < max_lenght[j]+1)
			max_lenght[i] = max_lenght[j]+1;
			ans = max(max_lenght[i],ans);
		}
	}
	return ans;
}

int main()
{
	int a[]={3,6,1,2,8,9,4,7,3,6,8,4,3,7,9,4,3};
	int n=sizeof(a)/sizeof(int);
	cout<<lis(a,n);
	return 0;
}


