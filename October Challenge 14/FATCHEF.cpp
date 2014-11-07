#include <bits/stdc++.h>
#define lli long long int
#define MOD 1000000009
using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

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

inline lli mulmod(lli a,lli b,lli c){
	lli x = 0,y=a%c;
	while(b > 0){
	if(b%2 == 1){
	x = (x+y)%c;
	}
	y = (y*2)%c;
	b /= 2;
	}
	return x%c;
}


int main(int argc, char** argv) {
	int cases;
	//freopen("in.txt","r",stdin);
	cin>>cases;
	while(cases--)
	{
		int n,m;
		n = read();
		m = read();
		// cout<<" read "<<m<<" "<<n<<endl;
		vector<pair<int,char> > v;
		while(m--)
		{
			char c;
			int x;
			c = GETCHAR();
			x = read();
			v.push_back(make_pair(x,c));
		//	cout<<" r "<<c<<" "<<x<<endl;
		}
		sort(v.begin(),v.end());
		
		lli ans = 1;
		pair<int,char> c,p;
		
		for(int i=1;i<v.size();i++)
		{	
			c = v[i];
			p= v[i-1];
			while( i+1 < v.size() && p.second == c.second)
			{
				p = c;
				c = v[++i];
			}
			if(i<n)
			ans   = mulmod(c.first - p.first,ans,MOD);
			else
			break;
		}
		write(ans);
	}
	return 0;
}
