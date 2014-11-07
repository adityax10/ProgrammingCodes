#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

map<char,int> m;

int main()
{
	string s1,s2;
	int cases;
	cin>>cases;
	while(cases--)
	{
	cin>>s1>>s2;
	int count =0;
	for(int i=0;i<s2.size();i++)
	m[s2[i]]++;
	for(int i=0;i<s1.size();i++)
	{
		if(m[s1[i]])
		{
			m[s1[i]]--;
			count++;
		}
	}
	cout<<count<<endl;
	m.clear();
    }
	return 0;
}


