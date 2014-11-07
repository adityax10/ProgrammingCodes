#include<stdio.h>

/*long long int p(int x,int y)
{
    long long int z=1;
    int i;
    for(i=0;i<y;i++)
    {
        z=(z*x)%1000000007;
        //z=z%1000000007;
    }
    return z;
}*/
#define MOD 1000000007
long long p(long long n,long long m)
{
if(m==0)
return 1;
long long temp=p(n,m/2)%MOD;
if(m%2)
return (((temp*temp)%MOD)*n)%MOD;
else
return (temp*temp)%MOD;
}

int main()
{
    int t,n,i,j;
    unsigned long long int ans=0;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
            scanf("%d",&n);
            for(j=1;j<=n;j++)
            {
                ans=(ans+p(26,((j+1)/2)));
            }
            printf("%lld\n",ans);
            ans=0;
    }
    return 0;
}
