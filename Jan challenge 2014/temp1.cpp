#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;

map<int,vector<int> > sl;
int main()
{
	sl[1].push_back(4);
	sl[1].push_back(5);
	sl[1].push_back(6);
	for(auto i = sl.begin();i!=sl.end();i++)
	{
		vector<int> x= (*i).second;
		cout<<((*i).second).[0];
	}
	

	return 0;
}


