#include<bits/stdc++.h>
using namespace std;

int cal_len(string s)
{
	int prev_index[256];
	for(int i=0;i<256;i++)
	prev_index[i]=-1;
	int len = 0;
	int start;
	start = 0;
	//O(n)
	for(int i=0;i<s.size();i++)
	{
		if(prev_index[s[i]]==-1)
		{
			prev_index[s[i]]=i;
			len = max(len , i - start + 1 );
			cout<<"Inc len for "<<s[i]<<" len "<<len<<endl;  
		}
		else
		{
			//repeated char is s[i]
			// so new length should begin from the last occurance ( prev_index[s[i]] +1 )of  character s[i]
			// start hold the starting of the string with distict characters
			cout<<"Setting new pos of start to "<<start<<endl;
			
			start = max ( prev_index[s[i]]+1 , start); // max cuz we dont want start to move backward of its current position
			
			len = max(len , i - start + 1 );
			cout<<"New Length "<<len<<endl;
			//setting new index for s[i]
			prev_index[s[i]]=i;
			
		}
	}
	return len;
	
}

int main()
{
	string s = "abcdcedf";
	cout<<cal_len(s);
	return 0;
}


