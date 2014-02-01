#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int find_min_xor(long arr[],int n)
{
	long a = arr[0];
	long b = arr[n-1];
	long x=INT_MIN;
	for(int i=1;i<n-1;i++)
	{
		x = max(a^b^arr[i],x);
	}
	return x;
}

int main()
{
	long a[2000];
	int n,tc;
	
	cin>>tc;
	while(tc--)
	{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<find_min_xor(a,n)<<endl;
    }
   return 0;
}
