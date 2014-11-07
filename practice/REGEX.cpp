#include<bits/stdc++.h>
using namespace std;

bool find_match(string regex,string buffer,int ri,int bi)
{
	if(ri>=regex.size())
	{
		return true;
	}
	
	if(regex[ri]=='?')
	return find_match(regex,buffer,ri+1,bi+1);
	else if(regex[ri]=='*')
	{
		for(int i=bi;i<buffer.size();i++)
		{
		//	if(!find_match(regex,buffer,ri,bi))
			
		}		
	}
	else if(regex[ri]==buffer[bi])
	{
		return find_match(regex,buffer,ri+1,bi+1);
	}
	else 
	return false;
}

int main()
{
	string pattern = "Adi?ya";
	string buffer  = "aAdityaVats";
	
	cout<<find_match(pattern,buffer,0,0);

	return 0;
}


