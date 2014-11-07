#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	string s,r;
	int cases;
	cin>>cases;
	while(cases--)
	{
		int p,q;
		vector<int> v(26);
		
		for(int i=0;i<26;i++)
		v[i]=0;
		
		cin>>s;
		cin>>p>>q;
		
		for(int i=0;i<s.size();i++)
		{
			v[s[i]-'a']++; 
		}
		
		for(int i=0;i<26;i++)
		{
			v[i]*=p; 
		}
		for(int i=1;i<26;i++)
		{
			v[i]+=v[i-1];
		}
		int x;
		while(q--)
		{
			cin>>x;
			int i=0;
			
			while( i< 26 && x>v[i])
			i++;
			if(i>25)
			cout<<"-1"<<endl;
			else
			cout<<char('a'+i)<<endl;
		}
	}
	return 0;
}

