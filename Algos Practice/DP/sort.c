#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

inline bool fx(int a,int b)
{
	return a<b;
}
int main()
{
	int a = {1,2,3,4,5};
	sort(a,fx);


	return 0;
}


