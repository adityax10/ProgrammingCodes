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

using namespace std;

vector< pair<int,int> > a,b;

int main()
{
   // freopen("input.txt","r",stdin);
	int test;
	//cin>>test;
	test = read();
	int n,k,p;
	while(test--)
	{
		int l,r;
		//cin>>n>>k>>p;
		n=read();
		k=read();
		p=read();
		
		a.resize(k);
		b.resize(p);
		
		int z=0;
		int _k=k;
		while(_k--)
		{
			//cin>>l>>r;
			l=read();
			r=read();
			a[z++] = make_pair(l,r);
		}
		z=0;
		int _p=p;
		while(_p--)
		{
			//cin>>l>>r;
			l=read();
			r=read();
			b[z++] = make_pair(l,r);
		}
		int i=0;
		int processed = 0;
		// now match
		while( i<k )
		{
			int x =  a[i].first;
			int y =  a[i].second;
			bool found = false;
			for(int j=0;j<p;j++)
			{
				int X = b[j].first;
				int Y = b[j].second;
			
				if(X<=Y)
				{
					if(x<=y && x>= X  && y <=Y)
					{
						processed++;
						i++;
						found = true;
						break;
					}
				}
				else // X>Y
				{
					if((x>=y && x>= X  && y <=Y)||(x<=y && x>=X && y>=X)||(x<=y && x<=Y && y<= Y))
					{
						processed++;
						i++;
						found = true;
						break;
					}
				}
			}
			if(!found)
			break;
		}
		
		if(processed ==  k)
			printf("Yes\n");
		else
			printf("No\n");		
	
	}
	
	return 0;
}


