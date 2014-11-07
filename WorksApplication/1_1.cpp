#include <bits/stdc++.h>
#define MAX 101


using namespace std;
pair<int,int> s;
pair<int,int> d;
	map<pair<int,int> , int> m;
class compareClass{
	public:
		bool operator() (pair<int,int> &x,pair<int,int> &y)
		{
			//cout<<"Comparing : "<<x.second<<" "<<y.second<<endl;
			if((x.second) > (y.second))  return true; // for min priority Heap
			//if (y > x) return true; //for max Heap
			else
			return false;
		}
};

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
		
		void DFScontroller(int source)
		{
			bool visited[v_n];
			for(int i=0;i<v_n;i++)
			visited[i]=0;
			
			// now visit each
			cout<<DFS(source,visited,v_n,0);
		}
		int DFS(int u,bool visited[],int n,int ans)
		{
			if(visited[u])
			return INT_MAX;
			
			if(n!=1 && m[d]==u)
				return INT_MAX;
			
			if(n==1 && m[d]==u)
			return ans ;
			
			visited[u]=1;
			for(int i=0;i<adj[u].size();i++)
			{
				edge e = adj[u][i];
				int v  = e.to;
				if(!visited[v])
				{
					int a = DFS(v,visited,n-1,ans+e.weight);
					if(a!=INT_MAX)
					{
					 	return a;
					}
					else
					{
						visited[v]=0;
					}
				}
			}
		}
		
};

class Orienteering
{	
	graph *g;
	int w,h;
	int visited[MAX][MAX];
	char a[MAX][MAX];
	public:
		Orienteering()
		{
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				visited[i][j]=0;
			}
		}
		void main();
		int find_dist(); 
		int bfs_dist(int i,int j)
		{
			
			 bool isSource = false;
			 bool isDest = false;
			 
			 if(s.first == i && s.second == j)
			 isSource = true ;// cout<<"is Source";
			 if(d.first == i && d.second == j)
			 isDest = true ;//cout<<"is dest";
			
			
			
			bool visited[MAX][MAX];
			for(int i1=0;i1<MAX;i1++)
			{
				for(int j1=0;j1<MAX;j1++)
				visited[i1][j1]=0;
			}
			queue< pair<int,int> > q;
			queue< int > dis;
			q.push(make_pair(i,j));
			dis.push(0);
			int count  = 0;
			while(!q.empty())
			{
				//int t;
				//cin>>t;
				pair<int,int> p = q.front();
				int count  = dis.front();
				dis.pop(); 
				q.pop();
				int x = p.first;
				int y = p.second;
				if((x<0 && x >= h) || (y<0 && y>=w ) || a[x][y] == '#')
				continue;
			//	cout<<"Poped => "<<x<<" "<<y<<a[x][y]<<endl;
				if(!visited[x][y] )
				{
			//	cout<<"Poped "<<x<<" "<<y<<a[x][y]<<endl;
				visited[x][y]=1;
				
				if(!(i==x && j==y) && a[x][y]!='.' && !(isSource && x==d.first && y==d.second ) && !(isDest && x==s.first &&y==s.second ))
				{
					g->addEdge(m[make_pair(i,j)],m[make_pair(x,y)],count);
				}
				
				
				q.push(make_pair(x,y+1));
				dis.push(count+1);
				q.push(make_pair(x+1,y));
				dis.push(count+1);
				q.push(make_pair(x,y-1));
				dis.push(count+1);
				q.push(make_pair(x-1,y));
				dis.push(count+1);	
				}
			}
		}
};

int Orienteering::find_dist()
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(a[i][j]=='@' || a[i][j]=='S' || a[i][j]=='G')
			{
				bfs_dist(i,j);
			}
		}
	}
	
	for(int i=0;i<g->v_n;i++)
	{
		for(int j=0;j<g->adj[i].size();j++)
		{
			edge e = g->adj[i][j];
		//	cout<<e.weight<<endl;
		}
		//cout<<endl;
	}
	
	g->DFScontroller(m[s]);
}

void Orienteering::main()
{
	cin >> w >> h ;
	int flags=0;
	int k=0;
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<h;j++)
		{
			cin >> a[i][j];
			if(a[i][j]=='@' || a[i][j]=='S' || a[i][j]=='G')
			{
				if( a[i][j]=='S')
				{
					s = make_pair(i,j);
				}
				if(a[i][j]=='G')
				{
					d = make_pair(i,j);
				}
				m[make_pair(i,j)] = k++;
			}
			if(a[i][j]=='@')
			flags++;
		}
	}
	g = new graph(flags+2,(flags+2)*(flags +2));
}

int main(int argc, char** argv) {
	freopen("int.txt","r",stdin);
	Orienteering o;
	o.main();
	o.find_dist();
	return 0;
}

