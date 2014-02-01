#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

map<char,char> m; //0th=> a/A 25th=> z/Z
vector<pair <char,int> > v;

bool cmp_fx(const pair<char,int> i,const pair<char,int> j)
{
	if(i.second!=j.second)
	return i.second>j.second;
	else
	{
		return i.first>j.first;
	}
}

int main()
{
	int i,cases;
	char f_s[100],c;
	char text[150010];
	scanf("%d",&cases);
	//c=getchar();
	while(cases--)
	{
	    i=0;
	    scanf("%[^\n]%*c",f_s);
		scanf("%[^\n]%*c",text);
		for(int i=0;i<strlen(text);i++)
		{
			if(text[i] >=97 && text[i]<=122) //lowercase
			m[text[i]]++;
			else if (text[i]>=65 && text[i]<=90) //uppercase
			m[text[i]+32]++;
		}
		map<char,char> ::iterator it;
		for(it=m.begin();it!=m.end();it++)
		{
			v.push_back(make_pair(it->first,it->second));
		}
		//sorting
		sort(v.begin(),v.end(),cmp_fx);
		int t=25;
		for(int i=0;i<v.size();i++)
		{
			m[v[i].first]=f_s[t--];
		}
		//printing
		for(int i=0;i<strlen(text);i++)
		{
			if(text[i] >=97 && text[i]<=122)
			printf("%c",m[text[i]]);
			else if (text[i]>=65 && text[i]<=90) 
			printf("%c",m[text[i]+32]-32);
			else
			printf("%c",text[i]);
		}
		printf("\n");
		m.clear();
		v.clear();
    }
	return 0;
}


