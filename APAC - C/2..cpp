#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	freopen("in1.txt","r",stdin);
	int cases;
	cin>>cases;
	int _n = 0;
	while(cases--)
	{
		_n++;
		bool a[10];
		vector<int> v;
		for(int i=0;i<10;i++)
		{
			cin>>a[i];
			if(a[i])
			v.push_back(i);
		}
		int n;
		cin>>n;
		int ans = 0;
		for(int i = v.size()-1;i>=0;i--)
		{
			while(n!=1 && v[i]!=1 && v[i]!=0 && n % v[i] == 0)
			{
				ans += 2;
				 n /= v[i];
			}
		}
		ans--;
		cout<<"N is "<<n<<endl;
		if(n==1)
		cout<<"Case #"<<_n<<": "<<ans<<endl;
		else
		cout<<"Case #"<<_n<<": Impossible"<<endl;
	}
	return 0;
}

