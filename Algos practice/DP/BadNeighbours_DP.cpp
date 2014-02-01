#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


int included[20];

int cal_max(int a[],int n)
{
	int max_sum[n]; // Max sum Upto i 
	for(int i=0;i<n;i++)
	max_sum[i]=0;
	// including a[0]
	max_sum[0]=a[0];
	
	int ans1,ans2;
	
	for(int i=2;i<n-1;i++)
	{
		max_sum[i]=max(max_sum[i-2]+a[i],max_sum[i-1]);
	}
	ans1 = max_sum[n-2];
	
	for(int i=0;i<n;i++)
	max_sum[i]=0;
	
	//including a[1]
	// Note that max_sum[0] is 0 ie a[0] is not included
	max_sum[1]=a[1];
	
	for(int i=2;i<n;i++)
	{
		max_sum[i]=max(max_sum[i-2]+a[i],max_sum[i-1]);
	}
	ans2 = max_sum[n-1];
	return max(ans1,ans2);
}

int main()
{
	//int a[] = {10, 3, 2, 5, 7, 8};
	//int a[]={ 11, 15 };
	//int a[]={ 7, 7, 7, 7, 7, 7, 7 };
	int a[]={ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	//int a[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  //6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  //52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	cout<<cal_max(a,sizeof(a)/sizeof(int));
	return 0;
}


