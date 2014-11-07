#include<iostream>
#define SIZE 11

using namespace std;

int l[SIZE][SIZE];

int lps(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		l[i][i]=1;
	}
	
	//c => length
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[0])
		{
		l[i][0]=1;
		l[n-1][i]=1;
	    }
		
	}
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				l[i][j]=l[i+1][j-1]+2;
			}
			else
			{
				l[i][j]=max(l[i][j-1],l[i+1][j]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<l[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int a[SIZE]={1,2,3,4,2,1,2,4,5,2,1};
	lps(a,SIZE);
}
