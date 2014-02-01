#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;

unordered_set<int> s;

int main()
{
	cout<< s.insert(1).second;
	cout<<s.insert(1).second;

	return 0;
}


