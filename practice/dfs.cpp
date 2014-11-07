#include<bits/stdc++.h>
using namespace std;

#define MAX =100

class graph
{
	public:
		vector<int> *adj;
		int v;
		int e;
		graph(int v,int e)
		{
			this->v = v;
			this->e =e;
			adj = new vector<int>[v];
		}
		void addEdge(int _u,int _v)
		{
			adj[_u].push_back(_v);
		}
		
		// DFS ROUTINE
		// MADE WITH LOVE
		void DFScontroller()
		{
			bool visited[v];
			for(int i=0;i<v;i++)
			visited[i]=0;
			
			// now visit each
			for(int i=0;i<v;i++)
			{
				if(!visited[i])
				DFS(i,visited);
			}
		}
		void DFS(int u,bool visited[])
		{
			if(visited[u])
			return;
			cout<<u<<" ";
			visited[u]=1;
			for(int i=0;i<adj[u].size();i++)
			{
				int v = adj[u][i];
				if(!visited[v])
				{
					DFS(v,visited);
				}
			}
		}
		
};


int main()
{
	int v,e;
	graph g(4,6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFScontroller(); 
 
	return 0;
}


