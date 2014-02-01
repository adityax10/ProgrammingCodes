#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int add(int x,int y)
{
	while(y)
	{
		int carry = x&y;
		x = x^y;
		y=carry<<1;
	}
	return x;
}

int main()
{
	cout<<add(-3,-5);

	return 0;
}


