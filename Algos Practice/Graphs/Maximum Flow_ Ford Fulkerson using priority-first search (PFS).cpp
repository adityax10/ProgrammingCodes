#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<queue>
#include<map>
#include<algorithm>
#define MAX 100
using namespace std;

class node{
	public : 
	int from,where,priority;
	node(int where,int from,int priority)
	{
		this->from = from;
		this->where = where;
		this->priority = priority;
   }
};

class compare_class{
	public:
		bool operator() (node &x,node &y)
		{
			//cout<<"Comparing : "<<x.second<<" "<<y.second<<endl;
			if((x.priority) > (y.priority))  return true; // for min priority queue
			//if (y > x) return true; //for max priority queue
			else
			return false;
		}
};

int g_r[MAX][MAX];
int pfs(int s,int d,int n)
{
	priority_queue<node,vector<node>,compare_class> pq;
	int visited[MAX],from[MAX];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		from[i]=-1;
	}
	pq.push(node(s,-1,INT_MAX)); // i want the nodes with min priority on the top
	int min_flow = 0;
	
	while(!pq.empty())
	{
		node a = pq.top();
		pq.pop();
		int where = a.where;
		int priority = a.priority;
		cout<<"Poped "<<where<<endl;
		int r;cin>>r;
		
		if(visited[where])
		continue;
		
		//NOTE
		from[where] = a.from;
		if(where == d)
		{
		min_flow = priority;
		break;
	    }
		
		visited[where] = 1;
		for(int next=0;next<n;next++)
		{
			if(g_r[where][next]> 0)
			{
				int new_cost= min(priority,g_r[where][next]);
				pq.push(node(next,where,new_cost));
			}
		}
		
	}	
	
	cout<<"Min Flow "<<min_flow<<endl;
	for(int j=0;j<n;j++)
	cout<<from[j]<<" ";
	cout<<endl;
	
	int where = d;
	
	while((from[where]) != -1)
	{
		cout<<"Vertex "<<from[where]<<" "<<where<<endl;
		g_r[from[where]][where] -= min_flow;
		g_r[where][from[where]] += min_flow;
		where=from[where];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<g_r[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<"Returning len "<<min_flow<<endl;
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
	while((x=pfs(s,d,n)) !=0)
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


