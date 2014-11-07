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

} while(i<j);

temp=a[p];
a[p]=a[j];
a[j]=temp;

return j;
}

int main()
{
    int n,m,z,i,j,max[50000],a[50000],sum_z=0,k=0;

  scanf("%d %d",&n,&m);

   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            max[k]=(a[i])^(a[j]);
            k++;
        }
    }
        quicksort(max,0,k-1);

        for(i=k-1;i>(k-1-m);i--)
        {
            sum_z=sum_z+max[i];
        }

        printf("%d",sum_z);

    }


