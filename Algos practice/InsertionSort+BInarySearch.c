#include<stdio.h>
#include<conio.h>

swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

 int binsearch(int start,int end,int elem,int arr[])
{
		//printf("Binsearching b/w %d and  %d for a[%d] = %d\n",start,end,elem,arr[elem]);
	if(end==start)
	{
	if(arr[end]>=arr[elem])
		return end;
	else if(arr[end]<arr[elem])
		return elem+1;
   }
	else if(end>start)
	{
		if(arr[elem]>arr[(end+start)/2])
		binsearch(((end+start)/2)+1,end,elem,arr);
		else if(arr[elem]<arr[(end+start)/2])
		binsearch(start,((end+start)/2)-1,elem,arr);
	}
}


main()
{
	int arr[10],i,j,n,pos;
	printf("No of Terms ? :");
	scanf("%d",&n);
	printf("Enter the terms :\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		j=i+1;
			pos=binsearch(0,i,j,arr);
			printf("Swappping %d and %d\n",arr[pos],arr[j]);
			swap(&arr[pos],&arr[j]);

	}

	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	getch();
}


