#include<iostream>
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


inline void write(int x) 
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


using namespace std;

int main()
{
	int a,b,n;
	a=read();
	b=read();
	n=read();
	int s=0;
	int days=0;
	while(1)
	{
		s+=a;
		days++;
		if(s>=n)
		{
			break;
		}
		else
		s-=b;
	}	
	write(days);
	return 0;
}


