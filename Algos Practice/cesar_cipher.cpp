#include<bits/stdc++.h>
using namespace std;

string ceaser_cipher(string s,int shifts)
{
	string x;
	x = s;
	for(int i=0; i<s.size() ; i++)
	{
		if(s[i]>=65 && s[i]<=90)
		{
			x[i] =  ((s[i] + shifts) > 90 ) ?  ( (s[i] + shifts)%91 + 65 ) : (s[i] + shifts) ;
		}
		else if(s[i]>=97 && s[i]<=122)
		{
			x[i] =  ((s[i] + shifts) > 122 ) ?  ( (s[i] + shifts)%123 + 97 ) : (s[i] + shifts) ;
		}
	}
	return x;
}


int main()
{
	int shifts = 2;
	string a = "abcz";
	cout<<ceaser_cipher(a,shifts);
	return 0;
}


