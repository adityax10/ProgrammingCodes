#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	unsigned int h1,m1,h2,m2;
	cin>>h1>>m1;
	cin>>h2>>m2;
	
	h1+=(m1+m2)/60;
	m1=(m1+m2)%60;
	
	h1=(h1+h2)%24;
	printf("%02d %02d\n",h1,m1);
	
	return 0;
}


