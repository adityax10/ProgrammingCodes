#include<bits/stdc++.h>
using namespace std;

int sum(int a[],int s,int e)
{
	int sm=0;
	for(int i=s;i<=e;i++)
	{
		sm += a[i];
	}
	return sm;}

int partition(int a[],int n,int k)
{	
	if(n==1)
	return a[0];
	
	if(k==1)
	return sum(a,0,n-1);
	
	int min_partition = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		min_partition = min (min_partition , max( partition(a,i,k-1) , sum(a,i,n-1) ));
	}
	return min_partition;
}

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int n=10,k=3;
	cout<<partition(a,n,k);
	return 0;
}


