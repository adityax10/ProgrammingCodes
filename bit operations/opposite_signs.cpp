#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<limits.h>
#include<algorithm>
using namespace std;

bool opposite_signs(int x,int y)
{
	return (x^y)>>31;
}

int main()
{
	cout<<opposite_signs(-2,1);
	return 0;
}


