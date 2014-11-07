#include<bits/stdc++.h>
using namespace std;

int max_diff(int a[],int n)
{
	int max_diff=a[1]-a[0];
	int min_num = a[0];
	for(int i=1;i<n;i++)
	{
		min_num = min( min_num , a[i]);
		max_diff = max(max_diff,a[i]-min_num);
	}
	return max_diff;
}

int main()
{
	int a[]={2,3,10,6,4,8,1};
	cout<<max_diff(a,sizeof(a)/sizeof(int));

	return 0;
}


