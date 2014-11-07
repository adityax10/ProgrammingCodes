#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


int lis(int a[],int n)
{
	int l[n+1];
	
	for(int i=0;i<n;i++)
	l[i]=1; //to Store the longest length found
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j] < a[i] && l[i] < l[j]+1 )
			l[i]=l[j]+1;
		}
	}
	int mx=0;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,l[i]);
	}
	return mx;
		
}

int main()
{
	int a[]={9,1,5,2,8,2,0,5,6};
	int n=sizeof(a)/sizeof(int);
	cout<<lis(a,n)<<endl;
	return 0;
}


