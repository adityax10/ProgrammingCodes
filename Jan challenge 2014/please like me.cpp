#include<iostream>
#include<vector>
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

inline long long int readLong() 
{
	int flag=1;
    long long int n = 0;
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

inline void write(ulli x) 
{
     int i = 20;
     char buf[21];
     buf[20] = '+';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '+');
}

int main()
{
	double l,s,c;
	unsigned long long d;
	int t;
	t = readLong();
	while(t--)
	{
		scanf("%lf",&l);
		d=readLong();
		scanf("%lf",&s);
		scanf("%lf",&c);
		
		unsigned long long int x =2;
		
		while(x<=d)
		{
			s = s*(1+c);
			x++;
			if(s>=l)
			break;
		}
		
		if(s < l)
		printf("DEAD AND ROTTING\n");
		else
		printf("ALIVE AND KICKING\n");
	}
	return 0;
}


