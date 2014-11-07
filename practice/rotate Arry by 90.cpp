#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=6,m=9;
	int a[n][m];
	// making a
	int x=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		a[i][j]=x++;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	int b[m][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		b[j][n-i-1] = a[i][j];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}	
	


	return 0;
}


