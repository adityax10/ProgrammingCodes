#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
int main()
{
	m['d']=3;
	m['a']=6;
	m['t']=33;
	
	map<char,int> :: iterator i;
	
	for(i=m.begin();i!=m.end();i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
	
	i = m.end();
	i--;
	cout<<i->second;
	
	return 0;
}


