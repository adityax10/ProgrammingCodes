#include<stdio.h>

int partition(int a[],int l,int r)
{
int p=l,i=l,j=r+1,q,temp;
   do{
	    do
	    {
	        i++;
	    }
	    while((a[i]<a[p])&&(i<r));
		do
		{
		    j--;
		}
		while((a[j]>a[p])&&(j>l));
		if(i<j)
		{
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;}
} while(i < j);

temp=a[p];
a[p]=a[j];
a[j]=temp;

return j;
}

void quicksort(int list[],int l,int r)
{
    if(r>l)
    {
    int q;
		q=partition(list,l,r);
		quicksort(list,l,q-1);
		quicksort(list,q+1,r);
    }
}


main()
{
    int arr[20],a,b;
    printf("enter the no of terms...");
    scanf("%d",&a);
    printf("enter data...");
    for(b=0;b<a;b++)
    {
        scanf("%d",&arr[b]);
    }
    quicksort(arr,0,a-1);
    for(b=0;b<a;b++)
    {
        printf(" %d ",arr[b]);
    }

}
