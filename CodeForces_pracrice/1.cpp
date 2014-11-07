#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	char v[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			char x;
			cin>>x;
			v[i][j]=x;
		}
	}
	
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=n-1 && v[i][j]=='o' && v[i][j+1]=='o')
			{
				c++;
			}
			if(i!=n-1 && v[i][j]=='o' && v[i+1][j]=='o')
			{
				c++;
			}
		}
	}	
	if(!(c%2))
	cout<<"YES\n";
	else
	cout<<"NO\n";
	return 0;
}

