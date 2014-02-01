#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;


#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif


inline unsigned long long int readLong() 
{
	int flag=1;
    unsigned long long int n = 0;
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

inline void writeInt(unsigned long long int x) 
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


map<unsigned long long int,bool> mx;

int main()
{
	unsigned long long int n,k,m,x;
	n=readLong();
	m=readLong();
	k=readLong();
	while(m--)
	{
		x=readLong();
		mx[x]=1;
	}
	while(k--)
	{
		x=readLong();
		writeInt(mx[x]);
	}
	return 0;
}


