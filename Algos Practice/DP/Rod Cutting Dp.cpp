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
	int max_price[n]; // max_cost for cutting to a picece of length i
	
	max_price[0]=p[0];
	max_price[1]=p[1];
	for(int i=2;i<=n;i++)
	{
		max_price[i]=p[i];
		for(int j=1;j<=i;j++)
		{
			max_price[i] = max(max_price[i],max_price[j]+p[i-j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<max_price[i]<<" ";
	}
}

int main()
{
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	int n=sizeof(p)/sizeof(int);

	rod_cut(p,n);
    return 0;
}


