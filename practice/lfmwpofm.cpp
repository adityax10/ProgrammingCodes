#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
	int len,cases,w[100000],i,j;
	
	cin>>len;
	cin>>cases;
	
	for(int i=0;i<len;i++)
	{
		cin>>w[i];
	}
	
	while(cases--)
	{
		int min=INT_MAX;
		cin>>i>>j;
		for(int k=i;k<=j;k++)
		{
			if(min>w[k])
			min=w[k];
		}
		cout<<min<<endl;
	}


	return 0;
}


