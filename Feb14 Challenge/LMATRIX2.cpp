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
	int cases;
	cin>>cases;
	int n,m;
	int a[100][100];
	int p[100][100];
	while(cases--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cin>>a[i][j];
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cin>>p[i][j];
		}
		
		int x1,x2,y1,y2,k;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]!=0)
				{
					k = abs(a[i][j]-p[i][j]);
					
					
				}
			}
		}
		
	}

	return 0;
}


