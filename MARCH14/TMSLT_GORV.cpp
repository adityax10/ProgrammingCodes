#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define mod 1000000
#include<stdio.h>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
inline long long readInt()
{
	int flag=1;
	long long n = 0;
	char c;
	while (1)
	{
		c=GETCHAR();
		if(c>='0'&&c<='9') 
		{
			n = n * 10 + c - '0';
			flag=0;
		}
		else if(flag!=1) break;
	}
	return n;
}
using namespace std;
int main()
{
	long long int t ;
	t=readInt();
	while(t--){
		long long int n,a,b,c,d;
		n=readInt();
		a=readInt();
		b=readInt();
		c=readInt();
		d=readInt();
		vector<bool> memo(1000001) ;
		vector<long long int> total(1000001) ;
		
		long long int x=d;
		for(int i = 0;i<n;++i)
		{
			long long int y;
			y=x%mod ;
			total[y]++ ;						
			memo[y]=true ;
			x=a*y*y+b*y+c;
			
		}
		
		long long int team1=0;
		long long int team2=0;
		long long int turn=0;
		for(int i=mod-1;i>=0;--i)
		{
			if(memo[i]==true)
			{
				
					if(turn%2==0)
					{
						team1=team1+(total[i]/2 +total[i] % 2)*i;
						
						team2 = team2 + ((total[i]-1)/2 + (total[i]+1)%2)*i ;
						 
					}
					
					else
					{
						team2=team2+(total[i]/2 +total[i] % 2)*i;
						
						team1 = team1 + ((total[i]-1)/2 + (total[i]+1)%2)*i ;
					}
					turn+=total[i] ;
			}
			
		}
		long long int ans=abs(team1-team2);
		cout<<ans<<"\n";
			
	}
}
