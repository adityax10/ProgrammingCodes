#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("incom.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int cases;
	cin>>cases;
	
	while(cases--)
	{
		string s;
		cin>>s;
		int last_pop=-1;
		vector<int> st;
		//bool flag=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='<')
			st.push_back(i);
			else if(st.size())
			{
				last_pop = i;
				st.pop_back();
			}
			else
			{
				break;
			}
		}
		
		if(last_pop==-1)
		cout<<0<<endl;
		else if(st.size()==0)
		cout<<last_pop+1<<endl;
		else
		cout<<st[0]<<endl;
	}
	return 0;
}


