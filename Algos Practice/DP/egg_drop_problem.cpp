#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int ed[MAX][MAX];

int egg_drops(int eggs,int floors)
{
	if(floors==0 || floors==1)
	{
		return floors;
	}
	if(eggs==1)
	{
		return floors;
	}
	
	if(ed[eggs][floors]!=INT_MAX)
	{
		
		return ed[eggs][floors];
	}

	int drops = INT_MAX;
	for(int i=1;i<=floors;i++)
	{
		drops = min( drops , max (egg_drops(eggs-1,i-1),egg_drops(eggs,floors-i)));
	}
	ed[eggs][floors]=drops+1;
	//cout<<"ed "<<eggs<<" "<<floors<<" "<<drops+1<<endl;
	return ed[eggs][floors];
}

int main()
{
	int eggs=2,floors=100;
	for(int i=0;i<=eggs;i++)
	{
		for(int j=0;j<=floors;j++)
		{
			ed[i][j]=INT_MAX;
		}
	}
	cout<<egg_drops(eggs,floors);
	return 0;
}


