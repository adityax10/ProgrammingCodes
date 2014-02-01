#include<stdio.h>
#include<conio.h>

int num=1;

void swap(int arr[],int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void permute(int arr[],int s,int n)
{
	int i;
	
	if(s==n)
	{
		printf("%3d : ",num);
		num++;
		for(int j=0;j<=n;j++)
		printf("%d",arr[j]);
		printf("\n");
	}

	for(i=s;i<=n;i++)
	{
		swap(arr,i,s);
		permute(arr,s+1,n);
		//swap(arr,i,s);
	}

}


int main()
{
	int arr[]={1,2,3,4},n;
	int size=sizeof(arr)/sizeof(int);
	permute(arr,0,size-1);
	getch();
	return 0;
}
