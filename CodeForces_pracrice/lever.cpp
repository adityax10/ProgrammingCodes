#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

vector<pair<int,unsigned long long> > p;

int main()
{
	string s;
	cin>>s;
	unsigned long long int c=0;
	for(unsigned long long int i=0;i<s.length();i++)
	{
		if(s[i]=='^')
		{
		c=i;
		break;
	    }
	    else if(s[i]!='=')
	    {
	    	p.push_back(make_pair(s[i]-48,i));
	    }
	}
	unsigned long long int rb=0,lb=0;
	for(unsigned long long int i=c+1;i<s.length();i++)
	{
		if(s[i]!='=')
		rb += (s[i]-48)*(i-c);
	}
	while(!p.empty())
	{
		pair<int,unsigned long long> x = p.back();
		p.pop_back();
		lb += (x.first)*(c-x.second);
	}
	if(lb==rb)
	{
		cout<<"balance";
	}
	else if(lb>rb)
	{
		cout<<"left";
	}
	else
	{
		cout<<"right";
	}
	cout<<endl;

	return 0;
}


