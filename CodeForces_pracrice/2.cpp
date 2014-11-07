#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	vector<long long> v(256);
	for(int i=0;i<256;i++)
	v[i]=0;
	string s;
	int k;
	cin>>k;
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++)
	v[s[i]]++;
	long long ans=0;
	sort(v.begin(),v.end());
	
	for(int i=255;i>=0;i--)
	{
		if(v[i]<=n)
		{
		ans += v[i]*v[i];
		n-=v[i];
		}
		else
		{
			ans += n*n;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

