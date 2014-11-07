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

int main()
{
	int cases;
	cases=read();
	int t;
	int count;
	lli ans;
	while(cases--)
	{
		lli count;
		ans=0;
		t=read();
		for(int a=1;a<=t/2;a++)
		{
			int d = t-a;
			int ad = a*d;
			
			for(int c=1;c*c<=ad;c++)
			{
				int b=ad/c;
				if(b*c==ad)
				b--;
				count=0;
				if(b>=c)
				count=2*(b-c) + 1;
				if(a==d)
				ans+= count;
				else
				ans+= 2*count;
			}
		}
		write(ans);
	}


	return 0;
}


