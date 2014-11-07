#include<bits/stdc++.h>
using namespace std;
#define SIZE 100005

int cal_dp(vector<int> &s)
{
	int n = s.size();
	int m[n+1];
	for(int i=0;i<n;i++)
	m[i]=100;
	m[n-1]=0;
	for(int i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;
	// equal
	int prev[10];
	for(int i=0;i<10;i++)
	prev[i]=-1;
	
	for(int i=n-1;i>=0;i--)
	{
		if(prev[s[i]]==-1)
		prev[s[i]]=i;
		else
		{
			m[i] = min (m[i],m[prev[s[i]]] + 1);
			prev[s[i]]=i;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;
	//front
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==100)
		continue;
		if( i-s[i-1] >=0 && i!=0)
		m[ i-s[i-1] ] = min ( m[i-s[i-1]] , m[i] + 1 );
	}
	for(int i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;
	//back
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==100)
		continue;
		
		if( i+s[i+1] < n && i!=n-1 )
		m[ i+s[i+1] ] = min ( m[i+s[i+1]] , m[i] + 1 );
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;
	return 0;
}

int main()
{
	freopen("in_digi.txt","r",stdin);
	vector<int> v;
	char x;
	while(cin>>x)
	{
		v.push_back(x-'0');
	}
	
	cout<<cal_dp(v);
	return 0;
}


