#include <bits/stdc++.h>

using namespace std;

// Graph has euler curcuit only iff
// 1) it is connnected
// 2) it is even

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
		
		// addEdge
		void addEdge(int _u,int _v)
		{
			adj[_u].push_back(_v);
		}
		
		// DFS ROUTINE
		void eulerPath(int source)
		{
			bool visited[6][6];
			for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
				visited[i][j]=0;
			}
			
			// now start to visit
			if(DFS(source,visited,0))
			{
				cout<<"Path Possible\n";
			}
			else
			{
				cout<<"Not Possible\n";
			}
		}
		
		// DFS
		bool DFS(int u,bool visited[][6],int edges)
		{
			static int source = u;
			
			if(u==source && edges == e)
			{
				// cout<<"Found !!";
				return 1;
			}
			
			for(int i=0;i<adj[u].size();i++)
			{
				int v = adj[u][i];
				if(!visited[u][v])
				{
					visited[u][v]=1;
					// cout<<"Visit "<<u<<" "<<v<<endl;
					if(!DFS(v,visited,edges+1))
					{
					// cout<<"UnVisit "<<u<<" "<<v<<endl;
					visited[u][v]=0; // BACKTRACK
					}
					else
					{
						return 1;
					}
				}
			}
		}
};

int main(int argc, char** argv) {
	// Directed Graph
	graph g(6,10);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(4,2);
	g.addEdge(4,1);
	g.addEdge(3,5);
	g.addEdge(5,4);
	// 
	g.eulerPath(0); 
	
	return 0;
}

