#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

//O{n^2) Approach
int max_area_in_histogram(int* a,int size)
{
	int max_area=0,area_bw_j_n_i;
	for(int i=0;i<size;i++)
	{
		int min_height  = INT_MAX;
		for(int j=i;j<size;j++)
		{
			if(min_height > a[j] )
			min_height = a[j];
			area_bw_j_n_i = min_height * ( j-i +1);
			if(area_bw_j_n_i> max_area)
			max_area = area_bw_j_n_i;
			cout<<"Area : "<<area_bw_j_n_i<<endl; 
		}
	}
	return max_area;
}

int main()
{
	int a[] = 	{6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(a)/sizeof(int);
	cout<<max_area_in_histogram(a,n);

	return 0;
}


