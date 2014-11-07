#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	char str;
	int cases;
	vector<string> v;
	scanf ("%d", &cases);
	while(cases--)
	{
		string s;
		char c;
		int j=0;
		fflush(stdin);
		scanf("%c",&c);
		while(c!='\n')
		{
			if(c!=' ' && c!='\n')
			s[j++]=c;
			else
			{
				cout<<s<<endl;
				j=0;
				v.push_back(s);
			}
			
		}
		for(int i=0;i<=v.size()/2;i++)
		swap(v[i],v[v.size()-i]);
		
		for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	}
	return 0;
}

