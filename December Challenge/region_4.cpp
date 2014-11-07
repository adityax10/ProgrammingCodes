#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<limits.h>
using namespace std;

long long int a[100010];
long long int l[100010];
long long int r[100010];

unsigned int n,k;

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


inline void writeInt(long long int x)
{
     int i = 20;
     char buf[21];
     buf[20] = '\n';
     bool flag =0;
     if(x<0)
     {
     x=-x;
     flag=1;
     }
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     if(flag)
     buf[--i]='-';
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

long long int compute_l()
{
	long long int actual_max=a[1],max_so_far=a[1];
	l[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		actual_max = max(actual_max+a[i],a[i]);
		if(actual_max > max_so_far)
		{
			max_so_far = actual_max;
		}
		l[i]=max_so_far;
	}
}

long long int compute_r()
{
	long long int actual_max=a[n],max_so_far=a[n];
	r[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		actual_max = max(actual_max+a[i],a[i]);
		if(actual_max > max_so_far)
		{
			max_so_far = actual_max;
		}
		r[i]=max_so_far;
	}
}


int main()
{
	unsigned int cases;
	cases=readLong();
	while(cases--)
	{	
		n=readLong();
		k=readLong();
		//cin>>n>>k;
		for(unsigned int i=1;i<=n;i++)
		{
			a[i]=readLong();
		}
		
		compute_l();
		compute_r();
		long long int maxi=LONG_MIN;
		for(int i=1;i+k+1<=n;i++)
		{
			maxi= max(l[i]+r[i+k+1],maxi);
		}
		writeInt(maxi);
    }

	return 0;
}


