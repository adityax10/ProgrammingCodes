#include<bits/stdc++.h>
using namespace std;

// A=> Source
// B=> Intermediate
// C=> Destination

// Can't move directly from A to C or C to A...
// B has to be used in between for transfer between A to C or C to A.


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
	return 0;
}


