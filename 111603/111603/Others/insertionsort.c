#include<stdio.h>
void isort(int list[],int n)
{
int min,i,t,j,elem;

for(i=1;i<n;i++)
{
    elem=list[i];
j=i-1;
while((elem>list[j])&&(j>=0)){j--;}

while((elem<list[j])&&(j>=0))
{
t=list[j];
list[j]=list[j+1];
list[j+1]=t;
elem=list[j];
j--;}
}
for(i=0;i<n;i++)
printf(" %d ",list[i]);
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
    isort(arr,n);
}
