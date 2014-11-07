#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<unordered_map>
#include<algorithm>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
using namespace std;

inline int read() 
{
	int flag=1;
    int n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
      c=GETCHAR();
      if(i==0&&c=='-') parity=-1;
      else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
      else if(flag!=1) break; 
      i++;
    }
    return parity*n;
}

inline void write(int x) 
{
     int i = 20;
     char buf[21];
     buf[20] = '\n';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

vector<vector<int>> v;
bool g[30][30];

int dfs_visit(int n,bool visited[],int m)
{
	if(visited[n])
	{
	return 0;
    }
	visited[n]=1;
	cout<<"Visiting "<<n<<endl;
	cout<<"z : ";
	for(int i=0;i<m;i++)
	{
		if(!g[n][i])
		{
		cout<<i<<" ";
		visited[i]=1;
	    }
	}
	int x=0;
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		if(g[n][i] && !visited[i])
		{
		x = 1+dfs_visit(i,visited,m);
	    }
	}
	return 1;
}

int main()
{
	freopen("C:\\Users\\Aditya Vats\\Downloads\\Code Chef\\Tester\\test.txt","r",stdin);
	int n,m;
	n = read();
	m = read();
	int _m = m;
	while(_m--)
	{
		int x =  read();
		vector<int> v_in;
		while(x--)
		{
			int val;
			val = read();
			v_in.push_back(val);
	    }
	    v.push_back(v_in);
	   // cout<<"read 1\n";
	}
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	unordered_map<int,bool> map;
	for(int l=0;l<v.size();l++)
	{
		for(int i=0;i<v[l].size();i++)
		{
		//	cout<<"Setting "<<v[l][i]<<endl;
			map[v[l][i]]=1;
		}
		for(int k=0;k<v.size();k++)
		{
			//cout<<"l = "<<l<<" "<<"k = "<<k<<endl;
			if(l==k)
			{
			//	cout<<"break same\n";
				continue;
			}
			bool intersecting = 0;
			for(int j=0;j<v[k].size();j++)
			{
			//	cout<<"Check "<<v[k][j]<<endl;
				if(map[v[k][j]]==1)
				{
			//		cout<<"break\n";
					intersecting = 1;
					break;
				}
			}
			if(!intersecting)
			{
				//cout<<"Set\n";
				g[l][k]=1;
			}
	    }
	    map.clear();
    }
    
    for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v.size();j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
    int n_max = 0;
    bool visited[30];
    for(int i=0;i<n;i++)
    {
    	visited[i]=0;
    }
    for(int i=0;i<m;i++)
    {
    	cout<<"DFS on "<<i<<endl;
    	int x = dfs_visit(i,visited,m);
    	n_max  = max(n_max, x);
    	cout<<"Returned "<<x<<endl;
    	for(int i=0;i<m;i++)
    	visited[i]=0;
    }
    write(n_max);
    
	return 0;
}


