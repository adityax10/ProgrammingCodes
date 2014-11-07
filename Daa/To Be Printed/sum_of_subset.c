#include<stdio.h>
#include<conio.h>

void sos(int s,int k,int r);
int n,*w,m,*flag;
int main()
{
    int i,total=0;
    printf("enter no of weights: ");
    scanf("%d",&n);
    printf("enter desired sum: ");
    scanf("%d",&m);
    w=(int *)malloc(n*sizeof(int));
    if(w==NULL)
    {
        printf("memory not allocated");
        exit(0);
    }
    flag=(int *)malloc(n*sizeof(int));
    if(flag==NULL)
    {
        printf("memory not allocated");
        exit(0);
    }
    printf("enter %d weights: \n",n);
    for(i=0;i<n;i++)
    {
            scanf("%d",&w[i]);
            flag[i]=0;
            total=total+w[i];
    }
    printf("\npossible combinations for given sum:\n");
    sos(0,0,total);
    getch();
    return 0;
}

void sos(int s,int k,int r)
{
    int i;
    flag[k]=1;
    if(s+w[k]==m)
    {
        for(i=0;i<n;i++)
        printf("%d  ",flag[i]);
        printf("\n");
    }
    else if((s+w[k]+w[k+1])<=m)
            sos(s+w[k],k+1,r-w[k]);
    flag[k]=0;
    if(((s+r-w[k])>=m)&&((s+w[k+1])<=m))
    {
        sos(s,k+1,r-w[k]);
    }
}
