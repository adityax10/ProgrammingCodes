#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void tell(int *a)
{
	cout<<a[1];
}

int main()
{
	int a[4][4]={{0,1,2,3},{0,3,4,5},{0,5,6,7}};
	tell(a[1]);

	return 0;
}


