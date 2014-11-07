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
using namespace std;

inline int mulmod(int a,int b,int c){
	int x = 0,y=a%c;
	while(b > 0){
	if(b%2 == 1){
	x = (x+y)%c;
	}
	y = (y*2)%c;
	b /= 2;
	}
	return x%c;
}


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

vector<pair<int,int *>> v;
vector<int> a;
vector<int,int> pair;

int main()
{
	int x,y;
	x =  read();
	while(x--)
	{
		y = read();
		a.push_back(x);
		v.push_back(make_pair(y,&a[a.size()]-1));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(v[i].first!=a[i])
		{
			swap(a[i],*(v[i].second));
			
		}
	}


	return 0;
}


