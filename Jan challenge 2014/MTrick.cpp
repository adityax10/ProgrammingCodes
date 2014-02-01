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

ulli mulmod(ulli a,ulli b,ulli c){
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

vector<ulli> ar;
vector< pair< bool,int> > op; // 0=> add, //1=> multiply

int main()
{
	int cases,n;
	ulli a,b,c;
	string s;
	cases = readLong();
	while(cases--)
	{
		n = readLong();
		ulli i = n;
		while(i--)
		{
			ulli x;
			x = readLong();
			ar.push_back(x);
		}
		a = readLong();
		b = readLong();
		c = readLong();
		cin>>s;
		for(ulli j=0;j<n;j++)
		{
			if(s[j]=='A')
			{
				op.push_back(mp(0,j));
			}
			else if(s[j]=='M')
			{
				op.push_back(mp(1,j));
			}
			else if(s[j]=='R')
			{
				int s = n;
				for(int i=j;i<(j+n)/2;i++)
				{
					swap(ar[i],ar[s-1]);
					s--;
				}
				/*cout<<"After Swapping:";
				for(int i=0;i<ar.size();i++)
				{
				//writeLong(ar[i]);
				cout<<(ar[i]);
			    }	
				cout<<"\n";*/
			}               
			for(ulli i=0; i<op.size() && op[i].second<=j ;i++)
			{
				//cout<<"Entry : "<<i<<" "<<op[i].first<<" "<<op[i].second<<endl<<" a[j] "<<ar[j]<<endl; 
				if(op[i].first == 0 ) //add
				{
					ar[j] = (a+ar[j])%c;
				}
				else//multiplty
				{
					ar[j]=mulmod(ar[j]%c,b%c,c);
				}
			}
			//for(int i=0;i<n;i++)
			write(ar[j]%c);
			//cout<<endl;
		}
		printf("\n");
		ar.clear();
		op.clear();
		s.clear();
	}
	return 0;
}


