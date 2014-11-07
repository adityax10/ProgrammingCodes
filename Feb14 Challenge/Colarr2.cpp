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

int cob[1005];
int b[1005][1005];
int n,m;
int saved[1005][1005]; //ith tile,k remaining , 0 => not repaint,1=>repaint
int pts_upto[1005];

int cal_dp(int i,int k)
{
	//cout<<"in for "<<i<<endl;
	if(i>n)
	return 0;
		
	//cout<<"Doing for : "<<i<<endl;
	if(k<=0)
	{
	//cout<<"returning for k=0 pts form tile "<<i<<"pts : "<<pts_upto[n]-pts_upto[i-1]<<endl;
	return pts_upto[n]-pts_upto[i-1];
    }
	
	if(saved[i][k]!=INT_MIN)
	return saved[i][k];
	
	for(int j=1;j<=m;j++) //color
	{
	//	cout<<"Checking  for tile "<<i<<" for color "<<j<<" with repaints left "<<((j==cob[i])?k:k-1)<<endl;
		saved[i][k] =max( saved[i][k], b[i][j] + cal_dp(i+1,((j==cob[i])?k:k-1)));
	}
	//cout<<"Returing for "<<i<<" "<<saved[i][k]<<endl;;
	return saved[i][k];
}


int main()
{
	//freopen("input.txt","r",stdin);
	int cases,k,x;
	//cin>>cases;
	cases = read();
	while(cases--)
	{
		//cin>>n>>m>>k;
		n=read();
		m=read();
		k=read();
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			saved[i][j]=INT_MIN;
		}
		//blocks
		for(int i=1;i<=n;i++)
		{
			//cin>>cob[i];
			cob[i]=read();
		}
		//point
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			b[i][j]=read();
		}
		//net_points
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
			x=read();
			b[i][j]-=x;
		    }
		}
		//pts_upto
		pts_upto[0]=0;
		for(int i=1;i<=n;i++)
		{
			pts_upto[i] = b[i][cob[i]] + pts_upto[i-1];
	    }
		write(cal_dp(1,k));
	}
	return 0;
}


