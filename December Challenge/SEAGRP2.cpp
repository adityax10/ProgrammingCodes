#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef struct node{
	int nam;
	int degree;
	vector<struct node*> link;  
}node;

node nd[110];
bool visited[110];
int ans;


int main()
{
	int cases,n,m;
	cin>>cases;
	while(cases--)
	{
		cin>>n>>m;
		int x = m;
		for(int i=1;i<=n;i++)
		{
		nd[i].nam=i;
		nd[i].degree=0;
	    }
		while(x--)
		{
			int x,y;
			cin>>x>>y;
			nd[x].link.push_back(&nd[y]);
			nd[y].link.push_back(&nd[x]);
			nd[x].degree++;
			nd[y].degree++;
		}
		
	    }
	}
	

	return 0;
}


