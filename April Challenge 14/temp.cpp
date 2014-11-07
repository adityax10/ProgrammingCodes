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

#define lli  long long int
inline lli read() 
{
	int flag=1;
    lli n = 0;
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

inline void write(lli x) 
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

int store[100005][10];

int main()
{
	string s;
	int n,m;
	n=read();
	m=read();
	char c;
	int i=0;
	int _n = n;
	while(_n--)
	{
		c=GETCHAR();
		s[i++]=c;
	}
	int x,y;
	lli ans;
	// store of frequencies
	store[0][s[0]-48]++;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			store[i][j]=store[i-1][j];
		}
			store[i][s[i]-48]++;
	}
	
/*	for(int j=0;j<n;j++)
	{
		for(int i=0;i<=9;i++)
		{
			cout<<store[j][i]<<" ";
		}
		cout<<endl;
	}*/
	
	// now processsing m queys
	while(m--)
	{
		x=read();
		ans=0;
		for(int i=0;i<=9;i++)
		{
			ans += (lli)(abs((s[x-1]-48)-i)) * store[x-1][i];
		}
		write(ans);
	}

	return 0;
}


