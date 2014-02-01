
// Shortest path => O(V+E) approach only for DAGs
// 1)Initialse vetices and source
// 2)Toplogical sorting
// 3) relaxxing each adjracent edges of the vertex in the topological order

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<limits.h>
using namespace std;


typedef struct node
{
	int nam;
	vector<pair<int,int>>link; // vertex,length
	
}node;
node nd[100];
int visited[100];
vector<int> order;

void DFS_Visit(int x)
{
	if(!visited[x])
	{
	visited[x]=1;
	for(int i=0; i<nd[x].link.size() ;i++)
	{
		if(!visited[nd[x].link[i].first])
		{
			DFS_Visit(nd[x].link[i].first);
			order.push_back(nd[x].link[i].first);
		}
	}
    }
}

//Topological order ! 
void DFS(int s,int n)
{
	DFS_Visit(s);
	order.push_back(s);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
		DFS_Visit(i);
		order.push_back(i);
	    }
	}
}
int shortest_path[100];
void relax_edges_for_veterx(int u)
{
	for(int i=0;i<nd[u].link.size();i++)
	{
		if(shortest_path[nd[u].link[i].first] > shortest_path[u] + nd[u].link[i].second)
		{
		shortest_path[nd[u].link[i].first] = shortest_path[u] + nd[u].link[i].second;
	    }
    }
}

// vertex first in the topological order can be traversal has no outgoing edge from it
void  relax_topological_order(int s)
{
	for(int i=0;i<order.size();i++)
	{
	shortest_path[i]=9999;
    }
	shortest_path[s]=0;
	while(!order.empty())
	{
		int x = order.back();
		order.pop_back();
		relax_edges_for_veterx(x);
	}
}

int main()
{
	int n=6;
	
	nd[0].link.push_back(make_pair(1,5));
    nd[0].link.push_back(make_pair(2,3));
    nd[1].link.push_back(make_pair(3,6));
    nd[1].link.push_back(make_pair(2,2));
    nd[2].link.push_back(make_pair(4,4));
    nd[2].link.push_back(make_pair(5,2));
    nd[2].link.push_back(make_pair(3,7));
    nd[3].link.push_back(make_pair(4,-1));
    nd[4].link.push_back(make_pair(5,-2));
    
    DFS(0,n);
   
   /* //topological order for the DAG
   while(!order.empty())
    {
    	cout<<order.back();
    	order.pop_back();
    }*/
    
    // computing shortest path
    relax_topological_order(1);
    for(int i=0;i<n;i++)
    {
    	cout<<"Shortest Path to "<<i<<" :  "<<shortest_path[i]<<endl;
    }
	return 0;
}


