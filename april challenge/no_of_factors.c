#include<stdio.h>

int main()
{
    int i,j,count=0,primes=0,Nos=0;
    FILE *fptr=NULL;

   // fptr=fopen("C:\\Users\\Aditya Vats\\Downloads\\Code Chef\\april challenge\\list.txt","w");

    for(i=2;i<1000;i++)
    {
        for(j=2;j<=i;j++)
        {
           if(i%j==0)
           {count++;
           }
        }
        if(count%2)
        {
        //fprintf(fptr,"%d,",i);
        Nos++;
        }
        count=0;
    }
    printf("%d",Nos);
   // fclose(fptr);
}
