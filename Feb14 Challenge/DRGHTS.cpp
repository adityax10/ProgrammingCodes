#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline long long read() 
{
	long long flag=1;
    long long n = 0;
    char c;
    long long parity=1;
    long long i=0;
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

inline void write(long long x) 
{
     long long i = 20;
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


typedef struct node{
	bool win_opn;
	bool isconn;
	vector<long long> link;  
}node;

node nd[50005];
bool visited[50005];

long long bfs(long long x)
{
	long long q1=0;
	if(visited[x])
	return 0;
	queue<long long> q;
	q.push(x);
	while(!q.empty())
	{
		long long n = q.front();
		q.pop();
	//	cout<<"Poped "<<n<<endl;
		
		if(!visited[n])
		{
			if(nd[n].win_opn==1)
			q1++;
			visited[n]=1;
	//		cout<<"Visiting : "<<n<<endl;
			
			for(long long i=0;i<nd[n].link.size();i++)
			{
				if(!visited[nd[n].link[i]])
				{
	//			cout<<"Pushing "<<nd[n].link[i]<<endl;
				q.push(nd[n].link[i]);
			    }
			}
	    }
	}
	return q1;
}
long long open =0;
long long bfs_controller(long long n)
{
	long long ans = 0;
	for(long long i=1;i<=n;i++)
	{
		long long x = 0;
		if(!visited[i])
		{
			x = bfs(i);
			ans += x*(x-1)/2;
			if(x!=1)
			open+=x;
		}
	}
	return ans;
}


long long cal_q2(long long &chain,long long n)
{	
    long long len1=0,len2=0;
    
	if(chain!=0 && nd[n].win_opn)
	{
	long long x = chain;
	chain = 0;
	//cout<<"At "<<n<<" len returning :  "<<x<<endl;
	return x;	
	}
	
	visited[n]=1;
	for(long long i=0;i<nd[n].link.size();i++)
	{
		long long temp = nd[n].link[i];
		
	//	cout<<"temp "<<temp<<endl;
		if(visited[temp] || (nd[temp].link.size()<=1 && !nd[temp].isconn && !nd[temp].win_opn))
		{
	//	cout<<" Rej "<<temp<<endl;
		continue;
	    }
	    
		if(!nd[temp].win_opn)
		{
		chain++;
	//	cout<<"Inc, Visiting "<<temp<<" present len :  "<<chain<<endl;
		len1 += cal_q2(chain,temp);
		if(chain)
		chain--;
	    }
		
		if(nd[temp].win_opn)
		{
	//	cout<<" found opned.. wait.. i will return ,P l "<<chain<<endl;
		len2 += cal_q2(chain,temp);
	    } 
	//	cout<<"len found till "<<temp<<" is : "<<len1+len2<<endl;
	}
//	cout<<"Returning form  "<<n<<" len "<<len1+len2<<endl;
	return len1+len2;
}

long long q2_con(long long n)
{
	for(long long i=1;i<=n;i++)
	{
		nd[i].isconn = 0;
		if(!nd[i].win_opn)
		for(long long j=0;j<nd[i].link.size();j++)
		{
			if(nd[nd[i].link[j]].win_opn == 1)
			{
				nd[i].isconn = 1;
				break;
			}
		}
	}
	
	for(long long i=1;i<=n;i++)
	visited[i]=0;
	long long ans = 0;
	for(long long i=1;i<=n;i++)
	{
		long long x=0;
		if(nd[i].win_opn && !visited[i])
		{
		//	cout<<"q2 on "<<i<<endl;
			ans+= cal_q2(x,i);
		}
	}
	return ans;	
}


int main()
{
	//freopen("input.txt","r",stdin);
	long long n,m;
	bool b;
	//cin>>n>>m;
	n=read();
	m=read();
	for(long long i=1;i<=n;i++)
	{
		b=read();
		nd[i].win_opn = b;
	}
	long long x,y;
	for(long long i=1;i<=m;i++)
	{
		//cin>>x>>y;
		x=read();
		y=read();
		nd[x].link.push_back(y);
		nd[y].link.push_back(x);
	}

	write(bfs_controller(n));
	write(q2_con(n)+open);
	return 0;
}


