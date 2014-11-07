#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline int readInt() 
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

inline void writeInt(int x) 
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

typedef struct node
{
	int nam;
	vector< struct node* >link; //links
}node;

node c[1000010];
bool visited[1000010];

void dfs(int i)
{
	for(int x=0;x<c[i].link.size();x++)
	{
		if(!visited[c[i].link[x]->nam])
		{
		visited[c[i].link[x]->nam]=1;
		dfs(c[i].link[x]->nam);
	    }
    }
}

int find_disjoint_sets(int size)
{
	int disjoints=0;
	for(int i=1;i<=size;i++)
	{
		if(!visited[i])
		{
		disjoints++;
		dfs(i);
		}
	}
	for(int i=1;i<=size;i++)
	visited[i]=0;
	return disjoints;
}


int main()
{
	int n,m;
	n=readInt();
	m=readInt();
	
	for(int i=1;i<=n;i++)
	{
		c[i].nam=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		int c_n,c_l;
		c_n=readInt();
		c_l=readInt();
		c[c_n].link.push_back(&c[c_l]);
		c[c_l].link.push_back(&c[c_n]);
		
		if(c_n>c_l)
		{
			writeInt(find_disjoint_sets(n));
		}
	}
	
	return 0;
}


