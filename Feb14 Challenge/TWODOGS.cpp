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


int main()
{
	int n,k;
//	freopen("input.txt","r",stdin);
//	cin >> n >> k;
	n=read();
	k=read();
	int a[n];
	for(int i=0;i<n;i++)
	a[i]=read();
	
	int ans = INT_MAX;
	
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if( a[i]+a[j]==k)
			{
				int t1 = max(i+1,n-j); //opposite
				int t2 = max(i+1,j+1); // both left
				int t3 = max(n-i,n-j); //both right
				ans = min(ans,t1);
				ans = min(ans,t2);
				ans = min(ans,t3);
			}
		}
	}
	if(ans==INT_MAX)
	{
		printf("-1\n");
	}
	else
	printf("%d\n",ans);
	return 0;
}


