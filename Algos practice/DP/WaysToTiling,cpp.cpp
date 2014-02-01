#include<iostream>

#define SIZE 12

using namespace std;

int store_ways[SIZE][SIZE];

int ways(int i,int n)
{
	if(i>n)
	{
		return 0;
	}
	if(i==n)
	return 1;
	
	if(store_ways[i][n]!=0)
	return store_ways[i][n];
		
	store_ways[i][n] =  ways(i+2,n)+ways(i+1,n);
	return store_ways[i][n];
}

int main()
{
	int n=SIZE;
	cout<<ways(0,n);
}
