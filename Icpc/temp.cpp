#include<iostream>
using namespace std;

int bs(const int *a,int n,int x)
{
	int l=0,r=n-1;
	int mid;
	while(r>=l)
	{
		mid=(l+r)/2;
		
		if(a[mid]>x)
		{
			r=mid-1;
		}
		else if(a[mid]<x)
		{
			l=mid+1;
		}
		else
		{
			return mid+1;
		}
	}
	return -1;
}

int main()
{
	int a[5]={1,2,3,4,5};
	cout<<bs(a,5,5);
}
