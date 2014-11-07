#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ulli;


vector<char> l,r;
string w;


void print()
{
	ulli i=0;
	while(i<l.size())
	{
		cout<<l[i++];
	}
	cout<<"|";
	i=0;
	while(i<r.size())
	{
		cout<<r[i++];
	}
	cout<<endl;
}


void func(vector<char> &l,vector<char> & r)
{
	ulli i = 0;
	if(l.size()-r.size() > w.size())
		{
			cout<<"Impossible\n";
		}
		else
		{
			ulli av = (l.size() + r.size() + w.size());
			if(av%2 == 1)
			{
				cout<<"Impossible\n";
			}
			else{
				av = av/2;
				while(l.size()<av)
				{
					l.push_back(w[i]);
					i++;
				}
				while(r.size()<av)
				{
					r.push_back(w[i]);
					i++;
				}
				print();
			}
		}
}

int main()
{
	string s;
	cin>>s;
	cin>>w;
	vector<char> *v;
	v = &l;
	for(ulli i=0;i<s.size();i++)
	{
		if(s[i]=='|')
		{
			v = &r;
			continue;
		}
		v->push_back(s[i]);
	}
	//print();
	if(r.size()==l.size())
	{
		if(w.size()%2==1)
		{
			cout<<"Impossible\n";
		}
		else
		{
			ulli i;
			for(i=0;i<w.size()/2;i++)
			l.push_back(w[i]);
			while(i<w.size())
			r.push_back(w[i++]);
			print();
		}
	}
	else if(l.size() > r.size())
	{
		func(l,r);
	}
	else
	{
		func(r,l);
	}
	return 0;
}


