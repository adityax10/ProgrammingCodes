#include<stdio.h>
void bsort(int list[],int n)
{
int x,i=0,t,elem,count=1;
x=n;
b:
while(count!=0)
{
for(i=0;i<x-1;i++)
{
count=0;
if(list[i]>list[i+1])
{
t=list[i+1];
list[i+1]=list[i];
list[i]=t;
count++;
}
}
if(count!=0)
{
    x--;
}
}
for(i=0;i<n;i++)
{
    printf(" %d ",list[i]);
}
}

main()
{
    int arr[30],n,j;

    printf("Enter the number of elements..\n");
    scanf("%d",&n);
    printf("Enter the terms to be sorted..\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    bsort(arr,n);
}
