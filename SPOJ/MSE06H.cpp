#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
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

pair<long long,long long> p[1000005];

class BIT{
	long long bitSize;
	vector<long long> tree;
	public :
	//CONSTRUCTOR
	BIT(long long size)
	{
		bitSize = size+1;
		initialise();
	}
	//INITIALISE BIT
	void initialise()
	{
		tree.resize(bitSize);
		for(long long i=0;i<bitSize;i++)
		tree[i]=0;
	}
	//UPDATE
	void update(long long idx,long long val)
	{
		while(idx < bitSize && idx >0)
		{
			tree[idx]+=val;
			idx += (idx)&(-idx);
		}
	//	display();
	}
	
	void display()
	{
		for(long long i=1;i<bitSize;i++)
		cout<<tree[i]<<" ";
		cout<<endl;
	}
	
	// QUERY
	long long query(long long idx)
	{
	//	cout<<"Query for "<<idx<<endl;
		long long q = 0;
		while(idx > 0 && idx < bitSize)
		{
	//		cout<<"A index : "<<idx<<endl;
			q+=tree[idx];
			idx -= (idx)&(-idx);
		}
	//	cout<<"Ret "<<q<<endl;
		return q;
	}
};

long long compare(const pair<long long,long long> &x,const pair<long long,long long> &y)
{
	if(x.first!=y.first)
	return x.first<y.first;
	else
	return
	x.second<y.second;
}

int main()
{
	//freopen("input.txt","r",stdin);
	long long cases;
	//cin>>cases;
	cases = read();
	long long c = 1;
	while(cases--)
	{
		long long n,m,k;
		//cin>>n>>m>>k;
		n = read();
		m = read();
		k = read();
		long long i=0;
		long long _k=k;
		long long x,y;
		while(_k--)
		{
			x = read();
			y = read();
			//cin>>x>>y;
			p[i].first = x;
			p[i++].second=y;
	    }
	    sort(p,p+k,compare);
	    BIT b(m);
	    long long ans = 0;
	    for(long long i=k-1;i>=0;i--)
	    {
	    	//cout<<"Doing for "<<p[i].second<<endl;
	    	ans += b.query(p[i].second-1);
	    	b.update(p[i].second,1);
	    }
	    printf("Test case %lld: %lld\n",c,ans);
	    c++;
    }
	return 0;
}


