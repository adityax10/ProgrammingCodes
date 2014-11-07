#include<bits/stdc++.h>
using namespace std;

int cal_num(string s,int e)
{
	int n=0;
	for(int i=0;i<s.size();i++)
	{
		n = ( (s[i]-'0') +n*10 )%e;
	}
	return n;
}

int main()
{
	string a,b,c,d;
	int e;
	int cases;
	cin>>cases;
	while(cases--)
	{
	cin>>a>>b>>c>>d>>e;
	int x = cal_num(a,e);
	int y= cal_num(b,e);
	int z = cal_num(c,e);
	int p  = cal_num(d,e);
	cout<<__gcd(__gcd(__gcd(x,y),__gcd(z,p)),e)<<endl;
	}
	return 0;
}


