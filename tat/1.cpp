#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	vector<int> v;
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		long long int sum = 0;
		while(n--)
		{
			int x;
			cin>>x;
			sum+=x;
			v.push_back(x);
		}
		n = v.size();
		long long int m;
		cin>>m;
		m = m % sum;

		int i=0;
		if(m==0)
		{
			while(v[n-1]==0)
			{
				n--;
			}
			cout<<n<<endl;
		}
		else
		{
			while(m>0)
			{
				m -=v[i++];
			}
		 cout<<i<<endl;	
		}
		v.clear();
	}
}

