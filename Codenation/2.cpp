#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	map<int,int> val;
	int m[501];
	
	for(int k=0;k<n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+k==n)
			m[i]=n;
			else
			m[i]= (i+k) % n;
		}
		
		int j = m[1];
		int c = 0;
		while(j!=1)
		{
			j = m[j];
			c++;
		}
		val[c]=1;
	}
	cout<<val.size();
	return 0;
}

