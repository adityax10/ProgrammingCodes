#include<bits/stdc++.h>
using namespace std;

int find_min_Window(string s,string t)
{
	// sorted map to stored the indexes of chacters in s having same charactetrs as in t
	map<int,char> m;
	queue<int> q[256];
	
	int required[256];
	
	//initialising
	for(int i=0;i<256;i++)
	{
		required[i]=0;
	}
	
	// frequency of chacters in the string pattern t
	for(int i=0;i<t.length();i++)
	{
		required[t[i]]++;
	}
	
	int matched=0;
	int minWindowLen = INT_MAX;
	// now matching
	for(int i=0;i<s.length();i++)
	{
		if(!required[s[i]])
		continue;
		
		if(q[s[i]].size()<required[s[i]])
		{
			matched++;
			m[i]=s[i];
			q[s[i]].push(i);
		}
		else
		{
			//removing the earlier index
			int index_To_erase = q[s[i]].front();
			map<int,char> :: iterator it;
			it = m.find(index_To_erase);
			m.erase(it);
			// now add the new index
			m[i] = s[i];
			
			q[s[i]].pop();
			q[s[i]].push(i);
		}
		
		if(matched==t.size())
		{
			int s = m.begin()->first;
			map<int,char> :: iterator it = m.end();
			it--;
			int  e = it->first;
			cout<<"len : "<<e-s+1<<endl;
			minWindowLen = min(minWindowLen,e-s+1);
		}
	}
	return minWindowLen;
}

int main()
{
	string s = "ADOBECODEBANC";
	string t="ABC";
	cout<<find_min_Window(s,t);
	return 0;
}


