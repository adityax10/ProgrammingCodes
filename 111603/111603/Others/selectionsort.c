#include<stdio.h>
int ssort(int list[],int n)
{
int min,i,t,j;

for(i=0;i<n-1;i++)
{
    min=i;
    for(j=i+1;j<n;j++)
    {
    if(list[min]>list[j])
    {
        min=j;
    }
    }
        t=list[i];
        list[i]=list[min];
        list[min]=t;
}
return list;
}
main()
{
    int arr[30],n,j,*list;

    printf("Enter the number of elements..\n");
    scanf("%d",&n);
    printf("Enter the terms to be sorted..");
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    list=ssort(arr,n);
    for(j=0;j<n;j++)
     printf(" %d ",*(list+j));
}
