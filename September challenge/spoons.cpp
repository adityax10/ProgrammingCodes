#include<iostream>
#include<stdio.h>

using namespace std;

//long long c_a[100];

unsigned long long c(long long n,long long k)
{
	if(k>n/2)
	k=n-k;
	
	if(k==1)
	return n;
	
	else
	return (n*c(n-1,k-1))/k;
}

int main()
{
	
	FILE *fp;
	fp = fopen(".//spoons.txt","w");
	unsigned long long a[100][100];
	int j=0;
/*	for(int k=2;k<=62;k++)
	{
	i=c(k,k/2);
//	fprintf(fp,"%ld,",i);
	cout<<i<<",";
	j++;
    }
	*/
	for(int i=2;i<100;i++)
	{
		for(j=1;j<i;j++)
		{
			if(j==1||j==i-1)
			a[i][j]=i;
			else
			a[i][j] = a[i-1][j-1]+a[i-1][j];
			if(j==i/2)
			cout<<a[i][j]<<"\n";
			
		}
	}
	//cout<<"\n"<<j<<"\n";
	
	fclose(fp);
}
