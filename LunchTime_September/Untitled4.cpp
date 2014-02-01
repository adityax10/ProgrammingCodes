#include<iostream>
#include<limits.h>
using namespace std;

long max_v=INT_MIN;

void combinationUtil(long arr[], long data[], int start, int end, int index, int r)
{
    if (index == r)
    {
    	long x;
        x = data[r-3]^data[r-2]^data[r-1];
        max_v =max (x,max_v); 
        return;
    }
    
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

void printCombination(long arr[], int n, int r)
{ 
    long data[r];
    max_v=INT_MIN;
    combinationUtil(arr, data, 0, n-1, 0, r);
}


int main()
{
	long a[2000];
	int n,tc;
	
	cin>>tc;
	while(tc--)
	{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	printCombination(a,n,3);
	cout<<max_v<<endl;;
    }
   return 0;
}
