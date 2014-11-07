
#include<bits/stdc++.h>
using namespace std;

void move_discs(int n,string s,string d,string t)
{
	if(n==0)
	return ;
	//int x;
	//cin>>x;

	move_discs(n-1,s,t,d);
	cout<<"MOving "<<s<<" To "<<d<<endl;
	move_discs(n-1,t,d,s);
}

int main()
{
	int n= 2;
	move_discs(n,"S","D","T");
	return 0;
}


