#include<bits/stdc++.h>
using namespace std;

/*
Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].
*/

int compute_max_diff(int a[],int n)
{
	int min_index_left[n],max_index_right[n];
	min_index_left[0]=a[0];
	for(int i=0;i<n;i++)
	{
		min_index_left[i] = min ( a[i] , min_index_left[i-1]);
	}
	
	max_index_right[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		max_index_right[i] = max ( a[i] , max_index_right[i+1] );
	}
	
	int i=0,j=1;
	int max_diff=0;
	while(i<n && j<n)
	{
		if(min_index_left[i] < max_index_right[j])
		{
			max_diff = max( j-i , max_diff );
			j++;
		}
		else
		i++;
	}
	return max_diff;
}

int main()
{
	// O(nlog(n))
	vector< pair<int,int> > v;
	int a[] = {1,4,5,2,3,2,3};
	int n = sizeof(a)/sizeof(int);
	cout<<compute_max_diff(a,n);
	return 0;
}


