#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
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


vector< pair<int,int> > ind(1000000);

int main()
{
	int n,k;
    //freopen("input.txt","r",stdin);
//	cin >> n >> k;
	n=read();
	k=read();
	int a[n];
	for(int i=1;i<=n;i++)
	{
	a[i]=read();
    }
	
	for(int i=1;i<=n;i++)
	{
		ind[a[i]].first = -1;
		ind[a[i]].second = -1;
	}

	for(int i=1;i<=n;i++)
	{
		if(ind[a[i]].first==-1)
		{
			ind[a[i]].first=i;
		}
	}
	
	for(int i=n;i>=1;i--)
	{
		if(ind[a[i]].second==-1)
		ind[a[i]].second=i;
	}
	
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" "<<ind[a[i]].first<<" "<<ind[a[i]].second<<endl;;
	}*/
	
	int ans = INT_MAX;
	int r = n+1;
	
	for(int i=1;i<=n;i++)
	{
		//cout<<"Checking for :"<<a[i]<<endl;
		if( k-a[i]>0 && a[i]!=k-a[i] && (ind[k-a[i]].first!=0))
		{
			//cout<<"Got "<<k-a[i]<<endl;
			int a1 = min(ind[a[i]].first,r-ind[a[i]].first);
			int a2 = min(ind[a[i]].second,r-ind[a[i]].second);
			int A = min(a1,a2);
		 	int b1 = min(ind[k-a[i]].first,r-ind[k-a[i]].first);
			int b2 = min(ind[k-a[i]].second,r-ind[k-a[i]].second);
			int B = min(b1,b2);
			
			ans = min(ans,max(A,B));
			
			//cout<<"Ans : "<<ans<<endl;
		}
	}
	if(ans == INT_MAX)
	{
		PUTCHAR('-');
		PUTCHAR('1');
		PUTCHAR('\n');
	}
	else
	{
		write(ans);
	}
	return 0;
}


