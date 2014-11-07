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

int v[100005];

int main()
{
	int cases,x,ans,temp,n,_n;
	cases=read();
	while(cases--)
	{
		int i=0;
		n=read();
		_n = n;
		while(_n--)
		{
			x = read();
			v[i++]= x;
		}
		temp = v[0];
		temp--;
		ans = v[0];
		
		for(int i=1;i<n;i++)
		{
			if(temp < v[i])
			{
				ans += v[i]-temp;
				temp = v[i];
				temp--;
			}
			else
			{
				temp--;
			}
		}
		
		printf("%d\n",ans);
		ans=0;
	}

	return 0;
}


