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

int up[100][100];
int lef[100];
int ar[100][100];

void cal_up(int n,int m)
{
	for(int j = 1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1 && ar[i][j]!=-1)
			{
				up[i][j]=1;
				continue;
			}
			if(ar[i][j] !=-1)
			{
				if(ar[i-1][j]!=-1)
				up[i][j]= up[i-1][j]+1;
				else
				{
				up[i][j] = 1;
			    }
		    }
		}
	}
}

void cal_left(int n,int m)
{
	for(int i=1;i<=n;i++)
	{
	//	cout<<"i "<<i<<" : "; 
		for(int j=1;j<=m;j++)
		{
			lef[j] = j-1;
			while(lef[j] >0 && up[i][lef[j]] >=up[i][j])
			lef[j]=lef[lef[j]];
			cout<<lef[j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n,m,k,q;

	n = read();
	m = read();
	k = read();
	while(k--)
	{
		int x = read();
		int y = read();
		ar[x][y]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<m;j++)
		cout<<ar[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cal_up(n,m);
	cal_left(n,m);
	
	return 0;
}


