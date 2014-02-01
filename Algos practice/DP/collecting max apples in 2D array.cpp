#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

/*
Problem:
A table composed of N x M cells, each having a certain quantity of apples, is given.
You start from the upper-left corner. 
At each step you can go down or right one cell. 
Find the maximum number of apples you can collect. 
*/

int cal_max(int a[][4],int n,int m)
{
	int max_apples[n+1][m+1]; // max apples found upto cell [i,j]
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j])
			max_apples[i+1][j+1] =a[i][j];
			else
			max_apples[i+1][j+1]=0;
		}
	}
	
	for(int i=0;i<=n;i++)
	max_apples[i][0]=0;
	
	for(int i=0;i<=m;i++)
	max_apples[0][i]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m
		;j++)
		{
			max_apples[i][j] += max(max_apples[i][j-1],max_apples[i-1][j]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<max_apples[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return max_apples[n][m];
	
}

int main()
{
	int a[4][4]={
		{1,0,1,0},
		{0,0,1,2},
		{1,1,0,1},
		{1,0,0,1}
	};
	
	cout<<cal_max(a,4,4);

	return 0;
}


