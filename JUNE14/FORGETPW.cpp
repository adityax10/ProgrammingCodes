#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("c_forgetpw.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		vector<char> v(127);
		for(int i=0;i<127;i++)
		v[i]=-1;
		while(n--)
		{
			char c,p;
			cin>>c>>p;
			v[c]=p;
		}
		string s;
		cin>>s;
		bool has_decimal=0;
		for(int i=0;i<s.size();i++)
		{
			s[i] = v[s[i]]==-1 ? s[i] : v[s[i]];
			if(s[i]=='.' && !has_decimal)
			has_decimal =1;
		}
		int st =0;
		while(s[st]=='0' && st<s.size())
		st++;
		int f = s.size()-1;
		if(has_decimal)
		{ 
			while(s[f]=='0' && f>=st)
			f--;
			if(s[f]=='.')
			f--;
		}
		if(f<st)
			cout<<"0";
		else
		{
			for(int i=st;i<=f;i++)
			{
				cout<<s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}


