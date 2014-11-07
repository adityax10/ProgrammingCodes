#include<iostream>
#include<vector>
#include<utility>
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

int a[301][301];
bool visited[11];

int main()
{
	int q,n,i,j,x1,x2,y1,y2,ans;
	n=readint();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		a[i][j]=readint();
	}
	q=readint();
	while(q--)
	{
		ans=0;
		x1=readint();
		y1=readint();
		x2=readint();
		y2=readint();
		
		for(i=x1;i<=x2;i++)
		{
			for(j=y1;j<=y2;j++)
			visited[a[i][j]]=1;
		}
		for(int i=1;i<=10;i++)
		{
			if(visited[i]==1)
			ans++;
			visited[i]=0;
		}
		writeInt(ans);
    } 
	return 0;
}


