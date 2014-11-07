#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector< pair < pair<string,int>, int>  > v;

int main()
{
	v.push_back(make_pair(make_pair("Hiotesh",111609),34));
	cout<<v[0].first.second;
	return 0;
}


