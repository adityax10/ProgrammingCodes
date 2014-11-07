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
		
		sum1=0,sum2=0;
		prev_v = d;
		unordered_map <lli,lli> m;
		m[prev_v]++;
		
		n--;
		
		while(n--)
		{
			prev_v = (a*prev_v*prev_v + b*prev_v + c)%1000000;
			m[prev_v]++;
		}
		lli turn=1;
		for(auto i=m.end();i!=m.begin();i++)
		{
		//	cout<<"No : "<<i->first<<" freq "<<i->second<<endl;
		if(i->second!=0)
		{
			if(turn%2)
			{
				sum1+= ((i->second)/2 + (i->second)%2)*(i->first);
				sum2+= (i->second - (i->second)/2 - (i->second)%2 )*(i->first);
			}
			else
			{
				sum2+= ((i->second)/2 + (i->second)%2)*(i->first);
				sum1+= (i->second - (i->second)/2 - (i->second)%2)*(i->first);
			}
			turn+=i->second;
		//	cout<<"sum1 "<<sum1<< " sum2 "<<sum2<<endl;
		}
	    }
		
		lli ans = sum1-sum2;
		write(((ans)>0)?(ans):-ans);
	}

	return 0;
}


