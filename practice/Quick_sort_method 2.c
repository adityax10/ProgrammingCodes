#include<stdio.h>
quicksort(int list[],int l,int r)
{
    if(r>l)
    {
    int q;
q=partition(list,l,r);
quicksort(list,l,q-1);
quicksort(list,q+1,r);
    }
}

int partition(int a[],int l,int r)
{
int p=l,i=p,j,q=r,temp,x;

x=a[p];

for(j=p+1;j<=q;j++)
{
    if(x>=a[j])
    {
    i++;
    temp=a[j];
    a[j]=a[i];
    a[i]=temp;
    }
}
temp=a[p];
a[p]=a[i];
a[i]=temp;

return i;
}
main()
{
    int a,b;
    /*printf("enter the no of terms...");
    scanf("%d",&a);
    printf("enter data...");
    for(b=0;b<a;b++)
    {
        scanf("%d",&arr[b]);
    }*/
    int arr[]={9,8,7,6,5,4,3,2,1};
    a=9;
    quicksort(arr,0,a-1);
    for(b=0;b<a;b++)
    {
        printf(" %d ",arr[b]);
    }

}
