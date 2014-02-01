#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
vector<char> v;
int main()
{
	string s;
	cin>>s;
	int cases;
	int ans = 0;
	cin>>cases;
	while(cases--)
	{
		ans = 0;
		int x,y;
		cin>>x>>y;
		for(int i=x-1;i<=y-1;i++)
		{
			if(s[i]=='(')
			v.push_back('(');
			else if(s[i]==')')
			{
				if(!v.empty() && v.back()=='(')
				{
				v.pop_back();
			    ans++;
				}
			}
		}
		if(!v.empty())
		v.clear();
		cout<<ans<<"\n";
	}

	return 0;
}


