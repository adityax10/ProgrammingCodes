#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	int a[]={-1,2,5,2,-1,3,-1,-2};
	int n = sizeof(a)/sizeof(int);
	int k=2;
	int m1=INT_MIN,m2=INT_MIN;
	
	int curr_max=a[0];
	int f_max=a[0];
	int i_beg=0;
	for(int i=1;i<n;i++)
	{
		curr_max=(curr_max+a[i],a[i]);
		if(curr_max > f_max)
		{
			f_max =curr_max;
			if(i_beg==i-1)
			{
				// a set  is growing
			}
			i_beg = i;
		}
	}
	

	return 0;
}


