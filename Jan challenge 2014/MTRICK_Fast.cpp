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
#define mp make_pair 
using namespace std;
typedef unsigned long long int ulli;

inline ulli mulmod(ulli a,ulli b,ulli c){
    ulli x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


inline ulli readLong() 
{
	int flag=1;
    ulli n = 0;
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
     ulli i = 20;
     char buf[21];
     buf[20] = ' ';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != ' ');
}

ulli ar[1001];

int main()
{
	int cases,n;
	ulli a,b,c;
	char s[1010];
	cases = readLong();
	while(cases--)
	{
		ulli add=0;
	    ulli mul=1;
		n = readLong();
		ulli i = n;
		ulli x=0;
		while(i--)
		{
			ar[x++] = readLong();
		}
		a = readLong();
		b = readLong();
		c = readLong();
		for(int i=0;i<n;i++)
		{
			s[i]=GETCHAR();
		}
		s[i]=NULL;
		bool reverse  = false;
		int j =0,j_prev=j;
		int s_i = 0;
		int n_ = n;
		while(n_--)
		{
			if(s[s_i]=='A')
			{
				add+=a;
			}
			else if(s[s_i]=='M')
			{
				mul = mulmod(mul,b,c);
				add = mulmod(add,b,c);
			}
			else
			{
				reverse = !reverse;
				if(reverse)
				{
				j_prev = j;
				j = n-1;
			    }
				else
				{
					j = j_prev;
				}
			}
			write((mulmod(ar[j],mul,c)+add)%c);
			if(reverse)
			{
			j--;
			n--;
		    }
			else
			j++;
			s_i++;
		}
		PUTCHAR('\n');
	}
	return 0;
}


