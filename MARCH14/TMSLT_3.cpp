#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<unordered_map>
#include<algorithm>

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

#define lli long long int

using namespace std;

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
	lli cases,n,a,b,c,d;
	unsigned lli sum1,sum2;
	unsigned lli prev_v;
	cases = read();
	
	while(cases--)
	{	
		n = read();
		a = read();
		b = read();
		c = read();
		d = read();
		vector <lli> m(1000001);
		sum1=0,sum2=0;
		prev_v = d;
		m[prev_v]++;
		
		n--;
		
		while(n--)
		{
			prev_v = (a*prev_v*prev_v + b*prev_v + c)%1000000;
			m[prev_v]++;
		}
		lli turn=1;
		for(int i=1000000;i>=0;i--)
		{
			if(m[i]!=0)
			{
			//cout<<"No : "<<i<<" freq "<<m[i]<<endl;
			if(turn%2)
			{
				sum1+= ((m[i])/2 + m[i]%2)*(i);
				sum2+= (m[i] - m[i]/2 - (m[i]%2))*(i);
			}
			else
			{
				sum2+= ((m[i])/2 + m[i]%2)*(i);
				sum1+= (m[i] - m[i]/2 - (m[i]%2))*(i);
			}
			turn+=m[i];
			//cout<<"sum1 "<<sum1<< " sum2 "<<sum2<<endl;
		    }
		}
		
		lli ans = sum1-sum2;
		write(((ans)>0)?(ans):-ans);
	}

	return 0;
}


