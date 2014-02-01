#include<stdio.h>
#include<conio.h>



void swap(int a[],int x, int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
	//printf("Swapping %d and %d\n",a[x],a[y]);
}


void max_heapify(int a[],int i,int n)
{
	int l=2*i;
	int r=2*i+1;
	int largest;

	///if((l>n) && (r>n))
   	//return;
	
	
	//printf("Heaping for i= %d l=%d r=%d and n=%d\n",i,l,r,n);
	if((l<=n)&& a[l]>a[i])
	largest=l;
	else
	largest=i;
	if((r<=n) && a[largest]<a[r])
	largest=r;
	
	if(largest!=i)
	{
	swap(a,largest,i);
	//now mainting max heap property at the bottom heap of largest!
	max_heapify(a,largest,n);
    }
}

void build_max_heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n);
	}
}

void print_arr(int arr[],int n)
{

   for(int i=1;i<=n;i++)
	{
		printf("%d\t",*(arr+i));
	}
	printf("\n");
}

void heap_sort(int a[],int n)
{
    build_max_heap(a,n);
	int N=n;
    //printf("Swapping and replacing......\n");
	for(int i=n;i>=2;i--)
	{
		swap(a,i,1);
		//print_arr(a,N);
		n--;//excuding the last element from the heap cuz its the highest one in the available array
		max_heapify(a,1,n);
	}
}



main()
{
	int arr[20],n,i;
	printf("Elements ?  : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",(arr+i));
	}
   
   //building max heap called only once..!! intitaially
   //build_max_heap(arr,n);
   // sorting max heap
  heap_sort(arr,n);

   for(i=1;i<=n;i++)
	{
		printf("%d\t",*(arr+i));
	}

  getch();
}
