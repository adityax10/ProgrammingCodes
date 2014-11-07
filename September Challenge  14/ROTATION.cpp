#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	int i=0;
	while(i<n)
	cin>>v[i++];
	long s = 0;
	while(m--)
	{
		char c;
		cin>>c>>i;
		if(c=='C')
		s-=i;
		else if(c=='A')
		s+=i;
		else
		{
			i--;
			int a = (i-s)%n;
			if(a<0)
			a+=n;
			cout<<v[a]<<endl;
		}
		s%=n;
	}
	
	return 0;
}

