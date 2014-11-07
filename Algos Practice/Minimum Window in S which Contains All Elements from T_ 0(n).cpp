#include<bits/stdc++.h>
using namespace std;

int find_min_Window(string s,string t)
{
	// this approach is based in using 2 pointers
	int begin=0,end;
	int hasFound[256];
	int required[256];
	
	for(int i=0;i<256;i++)
	{
		hasFound[i]=0;
		required[i]=0;
	}
	for(int i=0;i<t.length();i++)
	{
		required[t[i]]++;
	}
	
	int matched = 0; 
	int min_window_length = INT_MAX;
	
	for(int i=0;i<s.length();i++)
	{
		if(!required[s[i]])
		continue;
		hasFound[s[i]]++;
		
		if(hasFound[s[i]]<=required[s[i]])
		{
			matched++;
		}
		
		if(matched ==  t.length())
		{
			end = i;
			while(required[s[begin]]==0 || hasFound[s[begin]] > required[s[begin]])
			{
				if(hasFound[s[begin]] > required[s[begin]])
				hasFound[s[begin]]--;
				begin++;
			}
			cout<<"end - begin +1 "<<end-begin + 1<<endl;
			min_window_length = min(min_window_length,end-begin + 1);
		}
	}
	return min_window_length;
}

int main()
{
	string s = "ADOBECODEBANC";
	string t="ABC";
	cout<<find_min_Window(s,t);
	return 0;
}


