#include<iostream>
#include<limits.h>
using namespace std;

int min_val=INT_MAX;

void cal_min(int a[],int i,int n,int val)
{
	if(i==0)
	{
	val = a[i];i++;
    }
	
	if(i>=n)
	{
		if(val < min_val)
		min_val = val;
		return;
	}
	
	cal_min(a,i+1,n,val-a[i]);
	cal_min(a,i+1,n,val+a[i]);
	cal_min(a,i+1,n,a[i]*val);
}

int main()
{
	int n,a[11];
	long tc;
	
	cin>>tc;
	while(tc)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
	   min_val = INT_MAX;
	   cal_min(a,0,n,0);
	   cout<<min_val<<endl;
	   tc--;
	}	
	return 0;
}
