#include<iostream>
#include<stdio.h>

using namespace std;

int a[1000000];

//THING TO NOTE : 
/*
SEE in sieve.txt
 */


int main()
{
	long long count=0;
	FILE *fp;
	 fp = fopen("primes.txt","w");
	 
	 //SIEVE
	for(long long j=2;j*j<=1000000;)//for the numbers
	{
		if(a[j]==0)
		{
			long long k;
			k=j*j; 
			while(k<=1000000)//shifts for crossing
			{
				a[k]=1;
				k+=j;
			}
	    }
	    if(j==2)
	    j++;
	    else
	    j+=2;//as even nos should not be considered
	}
	
	for(int i=2;i<1000000;i++)
	{
		if(a[i]==0)
		{
		fprintf(fp,"%ld,",i);
		count++;
	    }
	}
	cout<<count;
	fclose(fp);
	return 0;
}
