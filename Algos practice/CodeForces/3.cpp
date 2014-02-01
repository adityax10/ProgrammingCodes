#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

map<int,vector<int> > m;
map<int,int> oc;

int main()
{
	int n;
	vector<int> v;
	int d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
		oc[x]++;
	}
	int i;
	for(i=1;i<n;i++)
	{
		d = v[i]-v[i-1];
		if(m.size()!=3)
		{
			m[d].push_back(i);	
		}
		else
		{
			break;
		}
	}
	int count=0;
	for(auto i = m.begin();i!=m.end();i++)
	{
		vector<int> v = i->second;
		if(v.size() >=1)
		{
			count++;
		}
		if(count>2)
		{
			break;
		}
	}
	bool reocc = 0;
	for(auto i = oc.begin();i!=oc.end();i++)
	{
		if(i->second>1)
		{
			reocc = 1;
			break;
		}
	}
	
    if(m.size()>=3 || count>2)
	{
		cout<<"0\n";
	}
	else if(n==1)
	{
		cout<<"-1\n";
	}
	else if(i==n)
	{
		if(v.size()==2)
		{
			if((v[n-1]-v[0])%2==0)
			{
			 cout<<"3\n";
			 cout<<v[0]-d<<" "<<v[0]+(v[n-1]-v[0])/2<<" "<<v[1]+d<<endl;
		    }
		    else
		    {
		    	cout<<"2\n";
		    	cout<<v[0]-d<<" "<<v[1]+d<<endl;
		    }
		}
		else if(m.size()==1)
		{
			vector<int> z = m.begin()->second;
			if(z[0]!=0)
			{
			cout<<"2\n";
			cout<<v[0]-d<<" "<<v[n-1]+d<<endl;
		    }
		    else
		    {
		    cout<<"1\n";
			cout<<v[0]<<endl;
		    }
		}
		else
		{
			if(!reocc){
			cout<<"1\n";
			auto i = m.begin();
			int d1,d2;
			auto j = m.begin();
			j++;
			if(i->second.size() > j->second.size())
			{
				d1 = i->first;
				d2= j->first;
			}
			else
			{
				d1 = j -> first;
				d2=j->first;
			}
			vector<int> c;
			c =m[d2];
			cout<<v[c[0]] -d1<<endl;
		}
		else
		{
			cout<<"0\n";
		}
	}}
	
	return 0;
}


