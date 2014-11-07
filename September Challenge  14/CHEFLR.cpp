#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int cases;
	cin>>cases;
	while(cases--)
	{
		string s;
		cin>>s;
		int ans=1;
		bool t=0;
		for(int i=0;i<s.size();i++)
		{
			if(!t)
			{
				if(s[i]=='l')
				ans*=2;
				else
				{
					ans*=2;
					ans+=2;
				}
				t=1;
			}
			else
			{
				if(s[i]=='l')
				ans=2*ans-1 ;
				else
				{
					ans=2*ans+1;
				}
				t=0;
			}
			ans%=1000000007;
		}
		cout<<ans<<endl;
	}
	return 0;
}

