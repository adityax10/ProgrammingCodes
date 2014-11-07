#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector<int> m1(300);
vector<int> m2(300);

int main()
{
	string s1,s2;
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>s1;
		int count =0;
		for(int i=0;i<s1.size();i++)
		m1[s1[i]]++;
		int x;
		cin>>x;
		while(x--)
		{
			cin>>s2;
			//cout<<"C : "<<endl;
			if(s2.size()==s1.size())
			{
				for(int i=0;i<s2.size();i++)
				{
					m2[s2[i]]++;
				}
				bool flag = 0;
				for(int i=0;i<300;i++)
				{
					cout<<"Cmp "<<m2[s2[i]]<<" "<<m1[s2[i]]<<endl; 
					if(m2[s2[i]] != m1[s2[i]])
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				count++;
		    }
		}
		m1.clear();
		cout<<count<<endl;
    }
	return 0;
}


