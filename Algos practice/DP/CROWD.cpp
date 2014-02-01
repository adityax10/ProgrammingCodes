#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<algorithm>
using namespace std;

#define MOD 1000000007

int main()
{
	int i=1;
	int k=7;
	int count=0;
	for(int i=3;i<=128;i++)
	{
		for(int j=0;j<15;j++)
		{
		if((i & (k<<j)) >>j == 7)
		{
		//cout<<"i : "<<i<<" k "<<k<<endl;
		count++;
		break;
	    }
	    }
	    k=7;
	}
	cout<<count;
	return 0;
}


