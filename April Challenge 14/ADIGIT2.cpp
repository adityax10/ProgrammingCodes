#include<bits/stdc++.h>

using namespace std;

#define lli  long long int


int store[100005][10];

int main()
{
//	freopen("pa.txt","w",stdout);
	string s;
	lli n,m;
	//n=read();
	//m=read();
	cin>>n>>m;
	char c;
	lli i=0;
	lli _n = n;
/*	while(_n--)
	{
		c=GETCHAR();
		s[i++]=c;
	}*/
	cin>>s;
	
	lli x,y;
	lli ans;
	
	// store of frequencies
	store[0][s[0]-48]++;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			store[i][j]=store[i-1][j];
		}
			store[i][s[i]-48]++;
	}
	
	
	// now processsing m queys
	while(m--)
	{
	//	x=read();
	cin>>x;
		ans=0;

		for(int i=0;i<=9;i++)
		{
			if(((s[x-1]-48)-i) > 0)
			ans += ((lli)(s[x-1]-48-i)) * store[x-1][i];
			else
			ans += ((lli)(i-s[x-1]+48)) * store[x-1][i];
		}
	
		cout<<ans<<endl;
	}

	return 0;
}


