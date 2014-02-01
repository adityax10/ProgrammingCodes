#include<stdio.h>
#include<conio.h>

int n;
void obst();
float min,*p,*q,**w,**c;
int **r;

int main()
{
    int i,j;
    printf("enter no of identifiers: ");
    scanf("%d",&n);
    n=n+1;
    p=(float *)malloc((n)*sizeof(float));
    q=(float *)malloc((n)*sizeof(float));
    r=(int **)malloc((n)*sizeof(int *));
    for(i=0;i<n;i++)
            r[i]=(int *)malloc((n)*sizeof(int));
    w=(float **)malloc((n)*sizeof(float *));
    for(i=0;i<n;i++)
            w[i]=(float *)malloc((n)*sizeof(float));
    c=(float **)malloc((n)*sizeof(float *));
    for(i=0;i<n;i++)
            c[i]=(float *)malloc((n)*sizeof(float));
    printf("enter probab of success for %d elements: \n",(n-1));
    for(i=1;i<n;i++)
        scanf("%f",&p[i]);
    printf("enter probab of unsuccessful search for %d elements: \n",n);
    for(i=0;i<n;i++)
        scanf("%f",&q[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
                        r[i][j]=0;
    }
    obst();
    printf("root matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",r[i][j]);
        printf("\n");
    }
    printf("\nminimum cost is: %f",min);
    getch();
    return 0;
}

void obst()
{
    int i,j,m,k,l;
    for(i=0;i<(n-1);i++)
    {
        w[i][i]=q[i];
        r[i][i]=0;
        c[i][i]=0;
        
        w[i][i+1]=q[i]+q[i+1]+p[i+1];
        r[i][i+1]=i+1;
        c[i][i+1]=q[i]+q[i+1]+p[i+1];
    }
    w[n-1][n-1]=q[n-1];
    r[n-1][n-1]=0;
    c[n-1][n-1]=0;
    for(m=2;m<n;m++)
    {
        for(i=0;i<n-m;i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            
            k=r[i][j-1];
            l=r[i][j-1];
            
            min=c[i][l-1]+c[l][j];
            for(;l<=r[i+1][j];l++)
            {
                if((c[i][l-1]+c[l][j])<min)
                {
                    k=l;
                    min=c[i][l-1]+c[l][j];
                }
            }
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
}
