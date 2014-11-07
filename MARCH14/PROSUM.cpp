#include<stdio.h>
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
	int cases;
	cases = read();
	while(cases--)
	{
		int n,x;
		long long int _n=0,_n2=0;
		n = read();
		while(n--)
		{
			x = read();
			if(x==1 || x==0)
			continue;
			_n++;
			if(x==2)
			_n2++;
		}
		long long int ans = (_n*(_n-1)/2) - (_n2*(_n2-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}


