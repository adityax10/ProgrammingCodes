#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector<int> v;

int main()
{
	int q,n;
	cin>>q;
	while(q--)
	{
		int type,l,c,x;
		cin>>type;
		if(type==1)
		{
			cin>>x;
			v.push_back(x);
		}
		else
		{
			cin>>l>>c;
			while(c--)
			{
			for(int i=0;i<l;i++)
			{
				v.push_back(v[i]);
			}
		    }
		}
	}
	
	int ops;
	cin>>ops;
	while(ops--)
	{
		int x;
		cin>>x;
		cout<<v[x-1]<<" ";
	}


	return 0;
}


