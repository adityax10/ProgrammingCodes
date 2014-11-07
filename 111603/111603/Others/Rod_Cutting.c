#include<stdio.h>
#include<conio.h>

#define SIZE 10

int max(int x,int y)
{
   return x>y?x:y;
}

int rod_cut_values[SIZE];

int rod_cut(int p[],int n)
{
	if(n==0)
	return 0;
    if(rod_cut_values[n]!=0)
    return rod_cut_values[n];
    int i;
	int q = -1;
	for(i=1;i<=n;i++)
	q = max(q,p[i]+rod_cut(p,n-i));
	rod_cut_values[n]=q;
	printf("Max profit for n = %d is %d\n",n,q);
	return q;
}

void main()
{
	int p[SIZE],n,i;

	printf("Enter the Number of Cuttings Available : \n");
	scanf("%d",&n);
	printf("Enter the price of each cutting : \n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}


	rod_cut(p,n);
	getch();


}
