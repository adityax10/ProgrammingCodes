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
using namespace std;

int dp[250001];
int dp_prev[250001];

void LCS(char a[],char b[],int l_a,int l_b)
{
	int max_len=0;
	int max_j=0;
	for(int i=0;i<l_a;i++)
	{
		for(int i=0;i<l_b;i++)
		dp_prev[i]=dp[i];
		
		for(int j=0;j<l_b;j++)
		{
			if(a[i]==b[j])
			{
				if(j==0)
					dp[j]=1;
				else
					dp[j] = dp_prev[j-1]+1;
				if(max_len < dp[j])
				{
					max_len = dp[j];
					max_j=j;
				}
			}
			else
			{
				dp[j]=0;
			}
		}
	/*	for(int i=0;i<l_b;i++)
		cout<<dp[i]<<" ";
		cout<<endl;*/
	}
	if(max_len!=0)
	for(int i=max_j-max_len+1;i<=max_j;i++)
	printf("%c",b[i]);
	printf("\n%d\n",max_len);
}

int main()
{
	char a[250001],b[250001];
	int s_a=0,s_b=0;
	char c;
	c=GETCHAR();
	while(c!='\n')
	{
	a[s_a++]=c;
	c=GETCHAR();
    }
    a[s_a]=NULL;
	
	c=GETCHAR();
	while(c!='\n')
	{
	b[s_b++]=c;
	c=GETCHAR();
    }
    b[s_b]=NULL;
	
	LCS(b,a,s_b,s_a);

	return 0;
}


