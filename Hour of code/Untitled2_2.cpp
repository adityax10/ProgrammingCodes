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

int parent[1000001];
int   size[1000001];

int find(int i)
{
	while(parent[i]!=i)
	i=parent[i];
	return i;
}
void Union(int i,int j)
{
	if(i==j)
	return;
	int p1=find(i);
	int p2=find(j);
	if(p1==p2)
	return;
	if(size[p1]<size[p2])
	swap(p1,p2);
	parent[p2]=p1;
	size[p1]+=size[p2];
}

int find_disjoint_sets(int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
	if(parent[i]==i)
	count++;
    }
    return count;
}

int main()
{
	int n,m;
	n=readInt();
	m=readInt();
	
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
	
	for(int i=1;i<=m;i++)
	{
		int c_n,c_l;
		c_n=readInt();
		c_l=readInt();
		Union(c_n,c_l);
		if(c_n>c_l)
		{
			writeInt(find_disjoint_sets(n));
		}
	}
	
	return 0;
}


