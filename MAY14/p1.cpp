#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long > v;

int main()
{
	int cases;
	cin>>cases;
	unsigned long long  x;
	while(cases--)
	{	
		cin >> x ;
		v.push_back(x);
	}
	
	vector< unsigned long long> arr(v.size()) ;
	for(int i=v.size()-1;i>=0;i--)
	{
		arr[i] = (i == v.size()-1)? v[i] : v[i]^arr[i+1];
	}
	unsigned long long ans = 0 ;
	for(int i=0;i<v.size()-2;i++) {
		ans = ans|(arr[i+1]^v[i]) ;
	}
	ans |= v[v.size()-1] ;
	cout << ans << endl;
	return 0;
}


