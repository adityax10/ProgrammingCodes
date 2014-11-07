#include<bits/stdc++.h>
using namespace std;

void cal_towers(int n,char a,char b,char c)
{
	if(n<=0)
	return;
	
	cal_towers(n-1,'A','B','C'); // A to C using B
	cout<<a<<" -> "<<b<<endl;
	cal_towers(n-1,'C','B','A'); // C to A using B
	cout<<b<<" -> "<<c<<endl;
	cal_towers(n-1,'A','B','C'); // A to C using B
	
}

int main()
{
	cal_towers(2,'A','B','C'); // A to C using B
}


