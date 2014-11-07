#include<stdio.h>
#include<conio.h>

swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

main()
{
	int arr[10],i,j,n;
	printf("No of Terms ? :");
	scanf("%d",&n);
	printf("Enter the terms :\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			swap(&arr[j],&arr[j-1]);
		}
	}
	
	for(i=0;i<n;i++)
	printf("%d",arr[i]);
	getch();
}


