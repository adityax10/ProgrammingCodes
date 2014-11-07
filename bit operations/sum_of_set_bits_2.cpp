#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int count_set_bits_for(int num)
{
	if(num==0)
	return 0;
	return (num%2)+count_set_bits_for(num/2);
}

int count_set_bits_upto(int x)
{
	int count=0;
	for(int i=1;i<=x;i++)
	count += count_set_bits_for(i);
	return count;
}

int main()
{
	int n=3;
	cout<<count_set_bits_upto(n);

	return 0;
}


