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

int a[1000000],n,l[1000000];

int lis()
{
	for(int i=0;i<n;i++)
	l[i]=1; //to Store the longest length found
	int mx=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j] < a[i] && l[i] < l[j]+1 )
			{
			l[i]=l[j]+1;
			mx=max(mx,l[i]);
		    }
		}
	}
	return mx;		
}

int main()
{
	n=readLong();
	for(int i=0;i<n;i++)
	{
		a[i]=readLong();
    }
    writeInt(lis());
	return  0;
}

