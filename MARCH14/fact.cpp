#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define ulli unsigned long long int

ulli store[21];

ulli cal_fact(ulli x)
{
	if(x==1 || x==0)
	return 1;
	if(store[x]!=0)
	return store[x];
	store[x] = ( x * cal_fact(x-1))%1000000009;
	return store[x];
}



int main()
{
	freopen("fact.txt","w",stdout);
	cal_fact(20);
	for(int i=1;i<21;i++)
	{
		cout<<store[i]<<" ,";
	}
	
	return 0;
}


