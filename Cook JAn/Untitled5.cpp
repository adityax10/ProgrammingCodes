#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

bool a[1005][1005];

int col(int x1,int y1,int x2,int y2)
{
	for(int i = x1;i<x2;i++)
		{
			for(int j=y1;j<y2;j++)
			a[i][j]=1;
		}
}

int main()
{
	int cases;
	cin>>cases;
	int x1,x2,y1,y2;
	while(cases--)
	{
		int count =0;
		cin>>x1>>y1>>x2>>y2;
		col(x1,y1,x2,y2);
		cin>>x1>>y1>>x2>>y2;
		col(x1,y1,x2,y2);
		for(int i=1;i<=1001;i++)
		{
			for(int j=1;j<1001;j++)
			{
				if(a[i][j]==1)
				{
				count++;
			    }
				a[i][j]=0;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}


