#include<bits/stdc++.h>
using namespace std;


// use XOR
void find_num(int a[],int n)
{
	int x = 0;
	for(int i=0;i<n;i++)
	{
		x ^= a[i];
	}
	cout<< x;
}

int main()
{
	// only one element in array that is occurring odd number of times
	int a[] = {1,2,2,4,2,1,5,6,3,2};
	find_num(a,sizeof(a)/sizeof(int));
	return 0;
}


