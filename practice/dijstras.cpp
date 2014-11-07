#include<bits/stdc++.h>
using namespace std;

class edge
{
	public:
	int to; // towards
	int weight;
	edge(int data ,int weight)
	{
		to = data;
		this->weight  = weight;
	}
};

class graph
{
	public : 
	int v,e;
	vector<edge*> *adj;
	
	graph(int v,int e)
	{
		this->v = v;
		this->e = e;
		adj = new vector<edge*>[v];
	}
	
	void addEdge(int u,int v,int weight)
	{
		adj[u].push_back(new edge(v,weight));
	}
	
	void dijstras(int source)
	{
		int dist[v];
		priority_queue<int,vector<int>,compareClass> Q;
		for(int i=1;i<=v;i++)
		dist[i]=INT_MAX;
		dist[source]=0;
		Q.push(dist[source]);
		while(!Q.empty())
		{
			int u = Q.top();
			Q.pop();
			vector<edge*> l = adj[u];
			
		}
		
		
	}
	
	class compareClass{
		public:
			bool operator()(const int &a,const int &b)
			{
				return a > b; // MIN
			}
	};
	
};

int main()
{
	

	return 0;
}


