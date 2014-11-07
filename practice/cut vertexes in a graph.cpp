#include <bits/stdc++.h>

using namespace std;


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
			adj[_v].push_back(_u);
		}
		
		void cut_vertex(int x)
		{
			int min_num[v]; // lowest number vertex reachable from a vertex through atmost one back edge
			int dfs_num[v]; // dfs visit number
			bool visited[v]; 
			int parent [v];
			int cost = 0;
			for(int i=0;i<v;i++)
			{
				parent[i] = -1;
				min_num[i]=-1;
				dfs_num[i] =-1;
				visited[i] = 0;
			}
			dfs_for_cut(x,cost,visited,min_num,dfs_num,parent);
		}
		
		void dfs_for_cut(int x,int cost,bool visited[],int min_num[],int dfs_num[],int parent[])
		{
			if(visited[x])
			return;
			cout<<"Visiting : "<<x<<endl<<endl;;
			visited[x] = 1;
			int child_in_tree = 0;
			dfs_num[x] = min_num[x] = cost++;
			
			vector<int> :: iterator i;
			for(i= adj[x].begin() ; i!=adj[x].end() ; i++)
			{
				if(!visited[*i])
				{
					child_in_tree++;
					cout<<"First Visit : "<<*i<<endl;
					parent[*i] = x;
					dfs_for_cut(*i , cost , visited , min_num , dfs_num,parent);
					
					// CONDITION 1 : ROOT OF TREE IS CUT VERTEX
					if(parent[x]==-1 && child_in_tree>1)
					{
						cout<<"ROOT CUT VERTEX "<<x<<endl;
					}
					// CONDITION 2 :NODES OTHER THAN ROOT OF TREE IS CUT VERTEX
					// Is there a child i of x that cant reach the visited vertices 
					// before x then.. probably x is a cut vertex.
					if(parent[x]!=-1 && dfs_num[x]  <= min_num[*i] )
					{
						cout<<"CUT VERTEX "<<x<<endl;
					}
					
					min_num[x] = min (min_num[x],min_num[*i]);
		
					
					cout<<"Vals for : "<<x<<" : "<<dfs_num[x]<<" "<<min_num[x]<<endl;
				}
				else //  BACK EDGE
				{
					cout<<"Back Edge : "<<*i<<endl;
					min_num[x] = min (min_num[x],dfs_num[*i]);
					cout<<"Vals for : "<<x<<" : "<<dfs_num[x]<<" "<<min_num[x]<<endl;
				}
			}
		}
};

int main(int argc, char** argv) {
	graph g(7,7);
	
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,6);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(3,5);
	
	g.cut_vertex(0);
	     
	return 0;
}

