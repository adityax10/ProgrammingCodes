#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<char> v;
	
	int cases;
	int ans=0;
	cin>>cases;
	while(cases--)
	{
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(!v.empty() && s[i] == v.back())
			{
				v.pop_back();
			}
			else
			{
				v.push_back(s[i]);
			}
		}
		if(v.size()==0)
		{
			ans++;
		}
		v.clear();
	}
	cout<<ans<<endl;
	return 0;
}

