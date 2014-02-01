#include<iostream>

#define MAX 10

using namespace std;

void OBST(double p[],double q[],int n)
{
	double c[MAX][MAX],w[MAX][MAX];
    int r[MAX][MAX];
	
    int i,j,m,k,l;
    double mincost;
    for(i=0;i<=n-1;i++)
    {
        w[i][i]=q[i];
        r[i][i]=c[i][i]=0;
        w[i][i+1]=c[i][i+1]=q[i]+q[i+1]+p[i+1];
        r[i][i+1]=i+1;
    }
    w[n][n]=q[n];
    r[n][n]=c[n][n]=0;
    //optimising
    for(m=2;m<=n;m++)
        for(i=0;i<=n-m;i++)
        {
        	j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            l=r[i][j-1];
            k=l;
            mincost=c[i][l-1]+c[l][j]+w[i][j];
            //computing k
            while(l<=r[i+1][j])
            {
                if(mincost>c[i][l-1]+c[l][j]+w[i][j])
                {
                    k=l;
                    mincost=c[i][l-1]+c[l][j]+w[i][j];
                }
                l++;
            }
            //updating with new k
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
            cout<<" K : is : "<<k<<endl;
        }
        
        cout<<"Root is :"<<r[0][n]<<endl;
    	cout<<"Cost is  :"<<c[0][n]<<endl;
}

int main()
{
	double p[MAX]={0.15,0.10,0.05,0.10,0.20};
	double q[MAX+1]={0.05,0.10,0.05,0.05,0.05,0.10};
	
	OBST(p,q,MAX);
	
	return 0;
}

