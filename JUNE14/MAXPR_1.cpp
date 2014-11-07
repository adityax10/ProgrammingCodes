#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>

using namespace std;

#define PB push_back
#define i64 long long

#define MOD 1000000007
#define MAXN 200002
#define MAXD 99
#define MIND -99
#define DLEN 200

//#define gcc getchar_unlocked
#define gcc getchar

int n;
vector<int> a;
int gc;
int tww[MAXN];
int cv[101][DLEN],cvc[101];


int readPosInt()
{
    int ret=0;
    char c;
    c=gcc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gcc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gcc();
    }

    return ret;


}

int modPower(int aa,int b)
{
    i64 ret=1;
    aa%=MOD;
    i64 a=aa;

    while(b>0)
    {
        if(b&1)
        {
            ret*=a;
            ret%=MOD;
        }

        a*=a;
        a%=MOD;
        b/=2;
    }

    return (int)ret;

}

void pree()
{
    tww[0]=1;
    int i;

    for(i=1;i<MAXN;++i)
    {
        tww[i]=tww[i-1]<<1;
        tww[i]%=MOD;
    }
}


int main()
{

    freopen("MAXPR.txt","r",stdin);

    int cases,t,i,j,curr,d,p2,ans;

    //scanf("%d",&cases);
    cases=readPosInt();

    pree();

    while(cases--)
    {
        a.clear();
       
        memset(cv,0,sizeof(cv));
        memset(cvc,0,sizeof(cvc));

        //scanf("%d",&n);
        n=readPosInt();
        //printf("N\t%d\n",n);

        for(i=0;i<n;++i)
        {
            //scanf("%d",&t);
            t=readPosInt();
            //printf("A\t\t%d\n",t);
            a.PB(t);
        }

        gc=n+1;

        //++cv[a[0]];
        //++cv[0];
        ++cvc[a[0]];
        
        for(i=1;i<n;++i)
        {
            for(j=1;j<=100;++j)
            {
                //printf("DDD\n");
                if(cvc[j]>0)
                {
                	//cout<<"found for "<<a[i]<<" "<<j<<endl;
                    d=a[i]-j;

                    gc+=cv[j][d+MAXD]+cvc[j];
                    gc%=MOD;

                    cv[a[i]][d+MAXD]+=cv[j][d+MAXD]+cvc[j];
                    cv[a[i]][d+MAXD]%=MOD;
                    
                }
            }

            ++cvc[a[i]];
        }


        //p2=modPower(2,n);
        p2=tww[n];
        ans=p2-gc;

        if(ans<0)
        {
            ans+=MOD;
        }

        //printf("%d\t-\t%d\t=\t%d\n",p2,gc,ans);
        printf("%d\n",ans);
    }

return 0;
}
