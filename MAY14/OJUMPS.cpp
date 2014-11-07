#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int a;
	ios_base::sync_with_stdio(false);
	cin>>a;
	a = a%6;
	if(a==0 || a==1 || a==3)
	cout<<"yes\n";
	else
	cout<<"no\n";
	
	return 0;
}


