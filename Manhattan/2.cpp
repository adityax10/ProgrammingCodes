#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

unordered_map<int,bool> m;

int find_sum(vector<int> &v,int n)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			m[v[j]+v[i]]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			bool f = m.find(v[i]-v[j])->second;
			if(f)
			{
				count++;
				break;
			}
		}
	}
	return count;
}


int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	int i=0;
	while(n--)
	scanf("%d",&v[i++]);
	printf("%d",find_sum(v,i));
	return 0;
}

