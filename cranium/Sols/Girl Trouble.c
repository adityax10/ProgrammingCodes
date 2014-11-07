#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a,*min,n,m,k,count=0,i,j=0,price=0,MAX=32767;

    printf("N, M , K ??");
    scanf("%d%d%d",&n,&m,&k);

    a=(int *)malloc(n*m*sizeof(int));
    for(i=0;i<n*m;i++)
    {
        scanf("%d",(a+i));
    }
min=a;
    while(count!=k)
    {
        for(i=0;i<n;i++)
        {
            j=0;

            while(*(a+m*i+j)==-1)
            j++;
           // min=(a+m*i+j);
            if(*min>*(a+m*i+j))
            min=(a+m*i+j);

            j=m-1;

            while(*(a+m*i+j)==-1)
            j--;

            if(*min>*(a+m*i+j))
            min=(a+m*i+j);

            if(i<n)
            {
                printf("for i= %d, min value = %d \n",i,*min);
            }

            if(i==n-1)
            {
            count++;
            price=price+(*min);
            printf("min = %d,price= %d",*min,price);
            *min=-1;
            min=&MAX;
            }
        }

    }

}
