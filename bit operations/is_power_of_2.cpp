#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


bool is_power_of_2(int x)
{
	return !(x&(x-1));
}

int main()
{
	int x = 5;
	cout<<is_power_of_2(x);
	return 0;
}


