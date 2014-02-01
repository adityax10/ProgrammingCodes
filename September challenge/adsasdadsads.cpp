#include<iostream>
using namespace std;

#define MAX 10000
int flags[MAX/32+2]={-1};

#define isSet(n) (flags[n>>5]&(1<<(n&31)))
#define unset(n) flags[n>>5] &= ~(1<<(n&31));

bool array[MAX];
int main()
{
	cout<<sizeof(array)/sizeof(bool);

	
}
