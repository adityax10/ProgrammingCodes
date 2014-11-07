#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n,m;
	vector<pair<int,int>> lv,hv;
	int x,s,i=0;
	while(n--)
	{
		cin>>x>>s;
		if(s)
		lv.push_back(make_pair(x,i));
		else
		hv.push_back(make_pair(x,i));
		i++;
	}
	sort(lv.begin(),lv.end());
	sort(hv.begin(),hv.end());
	
	vector<int> ans;
	while(m)
	{
		
	}
	
	return 0;
}

