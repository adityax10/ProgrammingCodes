#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

/*
Given a list of N coins, their values (V1, V2, ... , VN), and the total sum S. 
Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), 
or report that it's not possible to select coins in such a way that they sum up to S
*/

int cal_min_coins(int *p,int n,int sum)
{
	int mn[n];
	for(int i=0;i<=sum;i++)
	{
		mn[i]=INT_MAX;
	}
	mn[0]=0;
	for(int i=1;i<=sum;i++)
	{
		cout<<"For sum "<<i<<endl;
		for(int j=0;j<n;j++)
		{
			cout<<"Checking for val :"<<p[j]<<endl;
			if((p[j]<=i )&& (mn[i-p[j]]+1 < mn[i]))
			{
			mn[i]=mn[i-p[j]]+1;
			cout<<"Updating wrt p[j]="<<p[j]<<endl;
	    	}   
		}
	}
	
	for(int i=0;i<sum;i++)
	{
		cout<<"Sum : "<<i<<" Coins : "<<mn[i]<<endl;
	}
	
}

int main()
{
	int p[]={1,3,5};
	cal_min_coins(p,3,11);
	return 0;
}


