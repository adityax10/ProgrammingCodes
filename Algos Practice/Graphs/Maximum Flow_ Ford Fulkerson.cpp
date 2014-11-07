
/*
Part I: Setup Start with null for all the edges;
Initialize residual network: Nf = N;

Part II: Loop
	repeat search for min_flow in residual graph g_r from s to t 
		if (min_flow!=INT_MAX)
	  		for (each edge(u,v) in path from s to t) 
	  		do 
	  			if (forward (u,v))
	   			f(u,v) = f(u,v) + min_flow;
	    		if (backward (u,v))
				f(u,v) = f(u,v) - min_flow;
				
	until (no augmenting path);
*/

// Complexity =>   O(E.V) 

#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100

#define GRAY 1
#define WHITE 0
#define BLACK 2

//int g[MAX][MAX]; // orignal graph
int g_r[MAX][MAX]; //g_r = >  residual graph

int bfs(int s,int d,int n)
{
	cout<<"in bfs "<<endl;
	queue<int> sk;
	int min_flow = INT_MAX;
	int visited[MAX];
	int from[MAX]; //from which vertex ,we came to where
	for(int i=0;i<n;i++)
	{
	visited[i]=WHITE;
	from[i]=-1;
	}
	sk.push(s);
	int where,next;
	// "from node" to "where node" having "next node" as its adjacent node
	// from[] stores "where node" from which we came to "next node"
	// from[] will be used !! :D Later
	
	while(!sk.empty())
	{
		where = sk.front();
		sk.pop();
		cout<<"Poped: "<<where<<endl;

		
		if(where==d)
		{
			break;
		}
		
		// if there was no space left in residual graph... then pop that edge..
		if(visited[where]==BLACK)
		{
			continue;			
		}
		
		cout<<" Visiting "<<where<<endl;
		for(int next=0;next<n;next++)
		{
			if(next!=where && visited[next]==WHITE && g_r[where][next])
			{
			visited[next]=GRAY;
			cout<<"Pushed : "<<next<<endl;
			sk.push(next);
			from[next]=where;
		    }
		}
		visited[where]=BLACK;
	}
	
	for(int j=0;j<n;j++)
	cout<<from[j]<<" ";
	cout<<endl;
	
	
	where = d;
	//backtracking the path from which we came to "where" (here initially destination) node:D
	// finding min vertex found in the path
	
	while( from[where] > -1)
	{
		cout<<"Vertex "<<from[where]<<" "<<where<<endl;
		min_flow =min(min_flow,g_r[from[where]][where]);
		cout<<"Min_flow : "<<min_flow<<endl;
		where = from[where];
		cout<<"Next Vertex "<<from[where]<<" "<<where<<endl;
	}
	if(min_flow == INT_MAX)
	min_flow=0;
	
	where = d;
	while(from[where] > -1)
	{
		// reducing the available capacity of the edge
		g_r[from[where]][where]-=min_flow;
		// increasing the backward edge()
		g_r[where][from[where]]+=min_flow;
		where = from[where];
	}
	// if no further flow was possible
	cout<<"Returning "<<min_flow<<endl;
	return min_flow;
}

int ff_max_flow(int g[][MAX],int s,int d,int n) // n=> vertices s=> source d=>destination
{
	//Initialize residual graph
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		g_r[i][j] = g[i][j];
	}
	int ans=0;
	//Loop to find Augmenting paths until none can be found
	int x;
	while((x=bfs(s,d,n)) !=0)
	{
	ans += x;
	}
	return ans;
}

int main()
{
    // Let us create a graph shown in the above example
    int n = 6;
    int g[MAX][MAX] =  {{0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}};

    cout << "The maximum possible flow is " << ff_max_flow(g,0,5,n);
    return 0;
}


