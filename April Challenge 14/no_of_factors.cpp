#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	//freopen("output.txt","w",stdout);
	int n=100;
	int count =0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
		
		if(n/i == i)
		count+=2;
		else
		count+=4;
		}
	}
	cout<<count<<",";
	
	return 0;
}


