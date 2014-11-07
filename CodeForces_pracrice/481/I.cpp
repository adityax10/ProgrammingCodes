#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int a = v[n-1],i=0;
	while(a-v[i] >=0 && i<n-1 )
	{
		a-=v[i];
		i++;
	}
	cout<<i+1<<endl;
	return 0;
}

