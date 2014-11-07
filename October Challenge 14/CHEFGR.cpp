#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n,_n,m,t;
		int x=0;
		cin>>n>>m;
		_n = n;
		while(_n--)
		{
			cin>>t;
			x+=t;
		}
		x+=m;
		if(x%n)
		cout<<"No\n";
		else
		cout<<"Yes\n";
	}
	return 0;
}

