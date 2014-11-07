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

typedef  long long int lli;

inline lli readint() 
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


lli a[1000000];

int main()
{
	int n,q;
	lli x;
    n=readint();
    for(int i=0;i<n;i++)
    {
    	a[n-i-1]=readint();
    }
    for(int i=1;i<n;i++)
    {
    	a[i]+=a[i-1];
    }
    q=readint();
    lli count =0;
    while(q--)
	{
		int op;
		op=readint();
		if(op==1)
		{
			int l,r;
			l=readint();
			r=readint();
			if(n-r-1>=0)
			writeLong(a[n-l]-a[n-r-1]);
			else
			writeLong(a[n-l]);
		}
		else
		{
			a[n]=readint();
			a[n]+=a[n-1];
			n++;
	    }
	}    
	return 0;
}


