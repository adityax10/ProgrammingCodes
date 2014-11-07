#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

//#define rio

int b[1005][1005];
int cob[1005];
int max_adv[1005];

int main()
{
	//#ifdef rio
	freopen("input.txt","r",stdin);
	//#endif
	
	int cases,n,m,k;
	int x,max_pt;
	cin>>cases;
	while(cases--)
	{
		int initial_profit = 0;
		cin>>n>>m>>k;
		//blocks
		for(int i=1;i<=n;i++)
		{
			cin>>cob[i];
		}
		//point
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			cin>>b[i][j];
		}
		//net cost
		for(int i=1;i<=n;i++)
		{
			 max_pt = INT_MIN;
			for(int j=1;j<=m;j++)
			{
				cin>>x;
				max_pt = max(max_pt,b[i][j]-x );
			//	cout<<b[i][j]-x<<" ";
			}
			//cout<<endl;
			max_adv[i] = max_pt - b[i][cob[i]] ;
			initial_profit+= b[i][cob[i]];
			cout<<"max found : "<<max_pt<<" max_adv "<<max_adv[i]<<endl;
		}
		
		sort(max_adv+1,max_adv+n);
		for(int i=1;i<n;i++)
		cout<<max_adv[i]<<" ";
		
		int add_on = 0;
		for(int i=n;(i>=1 && k!=0);i--)
		{
			if(max_adv[i]>0)
			{
				add_on+=max_adv[i];
				k--;
			}
			else
			break;
		}
		cout<<add_on + initial_profit<<endl;
	}

	return 0;
}


