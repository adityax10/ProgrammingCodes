#include<bits/stdc++.h>
using namespace std;

class graph
{
	public:
		int v, e;
		vector<int> *adj;
		// CONSTRUCTOR
		graph(int _v,int _e)
		{
			v=_v;
			e=_e;
			adj = new vector<int>[_v];
		}
		// ADD EDGE
		void addEdge(int u,int v)
		{
			adj[u].push_back(v);
		}
		// BFS
		void BFSContoller()
		{
			bool visited[v];
			for(int i=0;i<v;i++)
			visited[i]=0;
			for(int i=0;i<v;i++)
			{
				if(!visited[i])
				{
				BFS(i,visited);
				}
			}
		}		
		
		void BFS(int u,bool visited[])
		{
			queue<int> q;
			q.push(u);
			while(!q.empty())
			{
				u = q.front();
				q.pop();
				if(visited[u])
				continue;
				visited[u]=1;
				cout<<u<<" ";
				
				for(int i=0;i<adj[u].size();i++)
				{
					int v = adj[u][i];
					if(!visited[v])
					{
						q.push(v);
					}
				}
			}
		}
};

int main()
{
	graph g(8,10);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2 ,4);
    g.addEdge(4 ,6);
    g.addEdge(4 ,7);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3 ,5);
    g.BFSContoller();
	return 0;
}


