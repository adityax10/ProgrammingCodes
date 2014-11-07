#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int cases;
	string s;
	vector<int> v;
	cin>>cases;
	while(cases--)
	{
		cin>>s;
		int l = 0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='#')
			{
				if(l!=0)
				{
					v.push_back(l);
					l=0;	
				}
			}
			else
			l++;
		}
		int jmp = 0;
		int ans = 0;
		for(int i=0;i<v.size();i++)
		{
			if(jmp < v[i])
			{
				ans++;
				jmp = v[i];
			}
		}
		cout<<ans<<endl;
		v.clear();
	}
	return 0;
}

