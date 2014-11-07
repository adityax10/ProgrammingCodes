#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void rowadd(int *a,int r,int x,int n)
 {
    int i;
    for(i=0;i<n;i++)
    {
        *(a+n*r+i)=(*(a+n*r+i))+x;
    }
 }

 void coladd(int *a,int r,int x,int n)
 {

    int i;
    for(i=0;i<n;i++)
    {
        *(a+n*i+r)=(*(a+n*i+r))+x;
    }
 }

int main()
{

    int a,n,x,o,i,j=0,max=0;
    char c[10],rc[10]="RowAdd",cc[10]="ColAdd";

    scanf("%d%d",&n,&i);

    while(j<(n*n))
    {
        a[j]=0;
        j++;
    }
    j=0;
    while(j<i)
    {
        scanf("%s",&c);
        if(!strcmp(c,rc))
       {
        scanf("%d",&o);
        scanf("%d",&x);
        rowadd(a,o,x,n);
        }
        else if(!strcmp(c,cc))
        {
        scanf("%d",&o);
        scanf("%d",&x);
        coladd(a,o,x,n);
        }
        j++;

    }

    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(max<a[i][j]))
            max=a[i][j];
        }
    }

    printf("%d\n",max);
    return 0;
}
