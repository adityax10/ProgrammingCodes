#include<stdio.h>

int main()
{
    long long i,j,count=0,primes=0;
    FILE *fptr=NULL;

    fptr=fopen("C:\\Users\\Aditya Vats\\Downloads\\Code Chef\\april challenge\\list.txt","w");

    for(i=111;i<=500;i++)
    {
       // printf("%ld\n",i);
        for(j=2;j*j<=i;j++)
        {
           if(i%j==0)
           {count=1;
           break;}
        }
        if(count==0)
        {
        printf("%ld\n",i);
        fprintf(fptr,"%d,",i);
        primes++;
        }
        count=0;
    }
    printf("%d",primes);
    fclose(fptr);
}
