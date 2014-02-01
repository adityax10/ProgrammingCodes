#include<stdio.h>
#include<conio.h>

void merge(int list[],int l,int r)
{
    int mid;
    mid=(l+r)/2;
    int abc[30],i=l,j=mid+1,k=l;
    printf("Sorting A[%d] between A[%d] \n",l,r);

    while((i<=mid)&&(j<=r))
    {
    if(list[i]>=list[j])
    {
        abc[k]=list[j];
        j++;k++;
    }
    else if(list[i]<list[j])
    {
        abc[k]=list[i];
        i++;k++;
    }
    }
    if(i>mid)
    {
        while(j<=r)
        {
        abc[k]=list[j];
        k++;j++;
        }
    }
    else if(j>r)
    {
        while(i<=mid)
        {
        abc[k]=list[i];
        k++;i++;
        }}
    for(k=l;k<=r;k++)
        {
            list[k]=abc[k];
        }

}

void msort(int list[],int l,int r)
{
int mid;

if(l<r)
{
mid=(l+r)/2;
msort(list,l,mid);
msort(list,mid+1,r);
}
merge(list,l,r);
}

main()
{
    int arr[30],n,j;

    printf("Enter the number of elements..(<30)\n");
    scanf("%d",&n);
    printf("Enter the terms to be sorted..\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    msort(arr,0,n-1);
    for(j=0;j<n;j++)
    {
        printf(" %d ",arr[j]);
    }
    getch();
}
