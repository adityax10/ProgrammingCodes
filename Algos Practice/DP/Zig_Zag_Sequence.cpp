#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int find_len(int a[],int n)
{
	int gt_max_len[n], lt_max_len[n];
	gt_max_len[0]=0; // a[i+1]>a[i]
	lt_max_len[0]=0;


	for(int i=0;i<n;i++)
	{
		if(a[i+1]>a[i])
		{
			gt_max_len[i+1]=gt_max_len[i]+1;
			lt_max_len[i+1]=lt_max_len[i];
		}
		else if(a[i+1]<a[i])
		{
			lt_max_len[i+1]=lt_max_len[i]+1;
			gt_max_len[i+1]=gt_max_len[i];
		}	
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<gt_max_len[i]<<" "<<lt_max_len[i]<<endl;
	}
}

int main()
{
	int a[]={1,17,5,10,13,15,10,5,16,8};
	find_len(a,sizeof(a)/sizeof(int));
	return 0;
}


