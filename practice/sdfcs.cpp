#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binary_search(int v[],int x)
{
	int l=0;
	int r=9;
	while(r>=l)
	{
		int mid = (l+r)/2;
		
		if(v[mid]==x)
		return mid;
		else if(v[mid] > x)
		r=mid-1;
		else
		l=mid+1;
	}
	return -1;
}

int main()
{
	int v[]={0,1,2,3,4,5,6,7,8,9};
	cout<<binary_search(v,9);

	return 0;
}


