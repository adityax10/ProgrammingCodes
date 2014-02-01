#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<limits.h>
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
vector< pair <int,int> > v_mins;

void dfs(int x)
{
//cout<<"T V : "<<x<<endl;
if(!visited[x])
{
//cout<<"V : "<<x<<endl;
ans++;
visited[x]=1;
for(int i=0;i<nd[x].link.size();i++)
{
dfs(nd[x].link[i]->nam);
}
}
}
 
bool dfs_visit(int n,int m)
{
int prev_ans=2;
bool two_set = 0;
ans=0;
for(int i=1;i<=n;i++)
{
//cout<<"Seeking"<<i<<endl;
if(!visited[i])
{
dfs(i);
//cout<<"Ans :"<<ans<<endl;
if((ans%2) || nd[i].link.size()==0)
{
//cout<<"si\n";
return 0;
}
}
}
//cout<<"Final Ans :"<<ans<<endl;
/*if( !(ans%2) && (ans/2 == m))
{
// cout<<"2 waala"<<endl;
return 0;
}*/
return 1;
}

void remove_from_list(int min_vertex)
{
	//cout<<"Removing "<<min_vertex<<endl; 
	for(int k=0;k<nd[min_vertex].link.size();k++) //sacanning for connected vertices
	{
		if(!visited[nd[min_vertex].link[k]->nam]) // k index
		{
			//cout<<"Removing From adj liist of : "<<nd[min_vertex].link[k]->nam<<endl;
			int s_vetex = nd[min_vertex].link[k]->nam;
			int siz =nd[s_vetex].link.size();
			for(int l=0;l<siz;l++)
			{
				if(nd[s_vetex].link[l]->nam == min_vertex)
				{
					//cout<<"Found at position : "<<l<<endl;
					auto it = nd[s_vetex].link.begin();//&(nd[s_vetex].link[l];
					nd[s_vetex].link.erase(it+l);
					break;
				}
			}
		}
	}
}

void find_pairs(int n)
{
	int vnd =0;
	//for(int i=1;i<=n;i++)
	//v_mins.push_back(make_pair(nd[i].link.size(),nd[i].nam));
	//sort(v_mins.begin(),v_mins.end());
	//v_mins.clear();
	//for(int i=0;i<v_mins.size();i++)
	//cout<<v_mins[i].second<<" ";
	//cout<<endl;
	while(1)
	{
		int x=-1;
		int x_size = INT_MAX;
		for(int i=1;i<=n;i++)
		{
			if(nd[i].link.size()==0)
			{
				cout<<"NO\n";
				return;
			}
			if(!visited[i] && x_size > nd[i].link.size())
			{
				x=i;
				x_size = nd[i].link.size();
			}
		}
		//cout<<"Min Vertex : "<<x<<endl;
		if(x==-1)
		{
			break;
		}
		if(!visited[x])
		{
			vnd++;
			//cout<<"Working on it\n";
			visited[x]=1;
			int min_vertex_size = INT_MAX;
			int min_index= -1;
			int min_vertex = -1;
			//Min Vertex
			for(int j=0;j<nd[x].link.size();j++)
			{
				if(min_vertex_size > nd[x].link.size() && !visited[nd[x].link[j]->nam])
				{
					min_index = j;
					min_vertex_size = nd[x].link.size();
					min_vertex = nd[x].link[j]->nam;
				}
			}
			//cout<<"Min degree connected Vertex : "<<min_vertex<<endl;
			//removing froom graph
			if(min_index!=-1)
			{
			//	nd[x].link.erase(min_index);
				visited[min_vertex]=1;
				remove_from_list(min_vertex);
				remove_from_list(x);
			}
			
		}
   }
	for(int i=1;i<=n;i++)
	{
		if(nd[i].link.size()==0)
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

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
		bool has_deg_one = false;
		for(int i=1;i<n;i++)
		{
			if(nd[i].link.size()==1)
			{
				has_deg_one = true;
				break;
			}
		}
		if(!has_deg_one)
		{
			if( !(n%2) && dfs_visit(n,m))
			{
			cout<<"YES\n";
			}
			else
			cout<<"NO\n";			
		}
		else
		{
		find_pairs(n);
	    }
		for(int i=1;i<=n;i++)
		{
			visited[i]=0;
			nd[i].link.clear();
		}
	}
	return 0;
}


