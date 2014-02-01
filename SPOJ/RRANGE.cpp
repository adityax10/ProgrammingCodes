#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
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
typedef  long long int lli;

inline lli readint() 
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

inline void writeLong(long long int x) 
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


vector<pair<lli,lli> > a;


int main()
{
	lli n,q,u;
	//cin>>n>>u>>q;
	n=readint();
	u=readint();
	q=readint();
	lli l,r;
	while(u--)
	{
		//cin>>l>>r;
		l=readint();
		r=readint();
		a.push_back(make_pair(l,r));
	}
	
	while(q--)
	{
		long long int sum = 0;
		l=readint();
		r=readint();
		for(lli i=0;i<a.size();i++)
		{
			lli s = a[i].first;
			lli e = a[i].second;
			if((l<s && r <s )|| (l>e && r>e))
			continue;
			
			if(l<=s && r>= e)
			{
				lli n = e - s + 1;
				sum+= ((n)*(n+1))/2;
  			}
			else if(l<=s && r >= s && r <= e)
			{
				lli  n =  r - s + 1;
				sum+= ((n)*(n+1))/2;
			}
			else if(l>=s  && l<=e && r >= e)
			{
				lli a_s = 1 + (l-s);
				lli a_e = 1 + (e-s);
				sum+= ((a_s+a_e)*(e-l+1)) / 2;
			}
			else if (l>=s && r <=e)
			{
				lli a_s = 1+(l-s);
				lli a_e = 1+(r-s);
				sum+= ((a_s+a_e)*(r-l+1)) / 2;
			}
			sum = sum%10000;
		}
		writeLong(sum);
	}
	return 0;
}



