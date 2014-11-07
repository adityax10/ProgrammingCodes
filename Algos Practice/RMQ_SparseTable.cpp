//the overall complexity of the algorithm is <O(N logN), O(1)>
//  									preprocessing,retrival

#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int RMQ(int a[],int min_store[][100],int n)
{
	for(int i=0;i<n;i++)
	{
	min_store[i][0] = i;
	//cout<<min_store[i][0]<<" ";
    }
	
	for(int j=1;(1<<j) < n; j++ )
	{
	//	cout<<"Doing for Size : "<<j<<endl;
		for(int i=0;i<n;i++)
		{
	//		cout<<"i = "<<i<<endl;
			if(a[min_store[i][j-1]] < a[min_store[i+(1<<(j-1))][j-1]])
			min_store[i][j] = min_store[i][j-1];
			else
			min_store[i][j] = min_store[i+(1<<(j-1))][j-1];
		}
	}
}

int retrieve_min(int a[],int min_store[][100] ,int i,int j)
{ // both inclusive
	
	int k = log(j-i+1) / log(2); //log base 2 of(j-i+1)
	return min(a[min_store[i][k]] ,a[min_store[j-(1<<k)+1][k]] ); // min element at a[min[i][k]] or at a[min[j-pow(2,k)+1][k]]
}

int main()
{
	int a[]  = {7,1,2,3,41,8,34,67};
	int n = sizeof(a)/sizeof(int);
	int min_store[100][100];
	RMQ(a,min_store,n);
	
	cout<<retrieve_min(a,min_store,5,7);
	
	
	/*for(int j=0;(1<<j) < n; j++ )
	{
		cout<<"Size : "<<(1<<j)<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a[min_store[i][j]]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}


