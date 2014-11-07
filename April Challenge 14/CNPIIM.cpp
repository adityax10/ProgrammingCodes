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
     buf[10] = '\n';
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

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	int cases;
	cases=read();
	while(cases--)
	{
		int t;
		t=read();
		int count =0;
		int prev_inc=0;
		
		for(int a=1;a<=t/2;a++)
		{
			int d = t-a;
			if(d>a)
			{
				if(prev_inc!=0)
				{
					for(int i=(a-1)*(d+1) ; i<a*d ; i++)
					{
						for(int j=1;j*j<=i;j++)
						{
							if(i%j==0)
							{
								if(i/j==j)
								prev_inc+=2;
								else
								prev_inc+=4;
							}
						}
					}
					//cout<<prev_inc<<endl;
					count+=prev_inc;
				}
				else // will be called only once in the beginnning
				{
					for(int i=1;i<a*d;i++) // finding factors of numbers < a*d
					{
						for(int j=1;j*j<=i;j++)
						{
							if(i%j==0)
							{
								if(i/j==j)
								prev_inc+=2;
								else
								prev_inc+=4;
							}
						}
					}
					//cout<<prev_inc<<endl;
					count+=prev_inc;
				}
		    }
			else if(d==a)
			{
				prev_inc/=2;
				for(int i=(a-1)*(d+1);i<a*d;i++)
				{
					for(int j=1;j*j<=i;j++)
					{
						if(i%j==0)
						{
							if(i/j==j)
							prev_inc++;
							else
							prev_inc+=2;
						}
					}
				}
				count+=prev_inc;
			}
		}
		write(count);
	}
	return 0;
}


