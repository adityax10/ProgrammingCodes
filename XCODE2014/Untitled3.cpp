#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


int pow(int a,int n)
{
	int x=1,y=a;
	while(n)
	{
		if(n%2==1)
		{
			x = x*y; 
		}
		y = y*y;
		n = n/2;
	}
	return x;
}

int main()
{
	cout<<pow(2,10);


	return 0;
}


