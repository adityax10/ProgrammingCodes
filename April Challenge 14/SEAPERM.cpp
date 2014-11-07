#include<bits/stdc++.h>
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
     buf[10] = ' ';
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

int cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first<b.first;
}
int main()
{
	int cases;
	cases=read();
	while(cases--)
	{
		vector<pair<int,int> > v;
		int n,k,s;
		//cin>>n>>k>>s;
		n=read();
		k=read();
		s=read();
		int x,ind=1;
		while(n--)
		{
			x=read();
			v.push_back(make_pair(x,ind++));
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<v.size();i++)
		write(v[i].second);
		PUTCHAR('\n');
	}


	return 0;
}


