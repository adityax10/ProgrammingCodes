#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int rod_cut(int p[],int n)
{
	int min_price[n]; // min_cost for cutting to a picece of length i
	min_price[0]=0;
	min_price[1]=p[1];
	
	for(int i=2;i<=n;i++)
	{
		min_price[i]=p[i];
		for(int j=1;j<=i;j++)
		{
			min_price[i] = max(min_price[i],min_price[j]+p[i-j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<min_price[i]<<" ";
	}
}

int main()
{
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	int n=sizeof(p)/sizeof(int);

	rod_cut(p,n);
    return 0;
}


