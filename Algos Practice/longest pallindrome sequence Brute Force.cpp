#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s="forgeeksskeegfor";
	int max_len = 1;
	for(int i=0;i<s.size();i++)
	{
		for(int j=s.size()-1;j>i;j--)
		{
			//now match
			int start=i,end=j;
			while(s[start]==s[end] && start<=end && start<s.size() && end>=0)
			{
				start++;
				end--;
			}
			if(start>=end)
			{
				max_len = max(max_len,j-i+1);
			}
		}
	}
	cout<<max_len;
	return 0;
}


