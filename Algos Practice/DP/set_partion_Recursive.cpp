#include<bits/stdc++.h>
using namespace std;

bool cal_set_partition(int a[],int i,int s1,int s2,int n)
{
	if(i>n)
	return 0;
	if(i==n)
	{
		return s1==s2;
	}
	return cal_set_partition(a,i+1,s1+a[i],s2,n) || cal_set_partition(a,i+1,s1,s2+a[i],n);
}

int main()
{
	int a[] = {1,5,4};
	cout<<cal_set_partition(a,0,0,0,sizeof(a)/sizeof(int));
	return 0;
}


