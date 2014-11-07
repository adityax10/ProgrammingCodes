#include <bits/stdc++.h>

using namespace std;

// considering directed graph
class edge
{
	public :
	int to,from;
	int weight; 
	edge(int from,int to,int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}	
};

class graph
{
	public:
		vector<edge> *adj;
		int v_n;
		int e_n;
		int max_flow = 0;
		graph(int v,int e)
		{
			this->v_n = v;
			this->e_n =e;
			adj = new vector<edge>[v_n];
		}
		void addEdge(int _u,int _v,int weight)
		{
			adj[_u].push_back(*(new edge(_u,_v,weight)));
		}
		
		void show_state()
		{
			for(int i=0;i<v_n;i++)
			{
				for(int j=0;j<adj[i].size();j++)
				{
					edge e = adj[i][j];
					cout<<e.from<<" "<<e.to<<" "<<e.weight<<endl;
				}
				cout<<endl;
			}
		}
		
		int maxFlow(int source,int destination)
		{
			while(find_flow(source,destination))
			{
				show_state();
			}
		}
		
		bool find_flow(int s,int d) // find d from s N remove the min edge found
		{
			static int min_edge = INT_MAX;	
			if(s==d)
			{
				max_flow += min_edge;
				cout<<"found\n";
				return true;
			}
			
			for(int i=0;i<adj[s].size();i++)
			{
				edge *e = &adj[s][i];
				if(e->weight>0) // if flow is possible
				{
					min_edge = min (min_edge,e->weight);
					if(find_flow(e->to,d))
					{
						e->weight -= min_edge;
						return true;
					}
				}
			}
							
		}
		
};
		

int main(int argc, char** argv) {
	// DIRECTED GRAPH
	graph g(7,8);
	
	g.addEdge(0,1,3);
	g.addEdge(0,2,3);
	g.addEdge(1,3,3);
	g.addEdge(2,3,5);
	g.addEdge(2,4,4);
	g.addEdge(4,5,2);
	g.addEdge(5,6,3);
	g.addEdge(3,6,4);
	
	g.maxFlow(0,6);
	cout<<"MAX Flow Is : "<<g.max_flow<<endl;
	return 0;
}

