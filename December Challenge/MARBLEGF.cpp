#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int a[1000002];
vector< pair<int,int> > c;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline int readint() 
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

inline void writeLong(long long int x) 
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

int main()
{
	int n,q;
	char m;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	a[i]=readint();
    	a[i]+=a[i-1];
    }
    while(q--)
    {
    	int i,j;
    	cin>>m;
    	//cin>>i>>j;
    	i=readint();
    	j=readint();
    	if(m=='S')
    	{
    		long long int x =0;
    		for(int z=0;z<c.size();z++)
    		{
    			int y = c[z].first;
    			if(y >=i && y<=j)
    			{
    			    x+=c[z].second;	
    			}		
    	    }
    		writeLong((long long int)(a[j+1]-a[i]+x));
    	}
    	else if(m=='G')
    	{
    	c.push_back(make_pair(i,j));
    	}
    	else
    	 c.push_back(make_pair(i,-j));
    }
	return 0;
}


