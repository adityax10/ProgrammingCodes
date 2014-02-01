#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int included[20];

int cal_max(int a[],int i,int n)
{
	if(i>=n)
	return 0;
	
	if(i==n-1)
	{
	if(included[0]==1)
	{
	return -a[i];
    }
	else
	return a[i];	
	}
	included[i]=1;
	int sum1 = cal_max(a,i+2,n)+a[i];
	included[i]=0;
	int sum2= cal_max(a,i+1,n);
	return max(sum1,sum2);
}

int main()
{
	//int a[] = {10, 3, 2, 5, 7, 8};
	//int a[]={ 11, 15 };
	//int a[]={ 7, 7, 7, 7, 7, 7, 7 };
	//int a[]={ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	int a[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	cout<<cal_max(a,0,sizeof(a)/sizeof(int));
	return 0;
}


