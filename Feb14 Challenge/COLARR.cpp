#include<iostream>
#include<limits.h>
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

int points[1002][1002];
int color[1002];
int shift[1002];

inline int read_int() 
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

inline void write_int(int x) 
{
     int i = 10;
     char buf[11];
     buf[10] = '\n';
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
	int turns,n,m,k;
	int x,ma;
	turns = read_int();
	while(turns--)
	{
		n=read_int();
		m=read_int();
		k=read_int();
		for(int i=1;i<=n;i++)
		color[i]= read_int();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			points[i][j]= read_int();
		}
		int ini = 0;
		for(int i=1;i<=n;i++)
		{
			 ma = INT_MIN;
			for(int j=1;j<=m;j++)
			{
				x=read_int();
				ma=max(ma,points[i][j]-x );
			}
			shift[i] = ma - points[i][color[i]] ;
			ini+=points[i][color[i]];
		}
		sort(shift+1,shift+n+1);
		int plus = 0;
		for(int i=n;(i>=1)&&(k!=0);i--)
		{
			if(shift[i]>0)
			{
			plus+=shift[i];k--;
			}
			else
			break;
		}
		write_int(ini+plus);
	}
	return 0;
}


