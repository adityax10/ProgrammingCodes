#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[],int l,int r,int key)
{
	int mid;
	int n=r;
	while(r>=l)
	{
		 mid = (l+r)/2;
		
		if(a[mid] < key)
		{
			l=mid+1;
		}
		else if(a[mid] > key)
		{
			r = mid-1;
		}
		if(mid==0 && a[mid]>key  && a[mid+1] > key)
		return mid;
		else if(mid==n && a[mid]>key && a[mid-1]<key )
		return mid;
		if(a[mid]>key && a[mid-1]<key && a[mid+1] > key )
		return mid;
	}
	
}


int main()
{
	int a[]={0,5,19,22,33,44,56,89};
	cout<<bin_search(a,0,7,55);
	return 0;
}


