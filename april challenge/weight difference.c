#include<stdio.h>

void merge(int list[],int l,int r)
{
    int mid;
    mid=(l+r)/2;
    int abc[30],i=l,j=mid+1,k=l;

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
merge(list,l,r);
}
}

int main()
{
    int n=0,j=0,k=0,sum_son=0,sum_dad=0,cases=0,check=0;
    int arr[100];

    scanf("%d",&cases);
    while(cases>0)
    {
    scanf("%d %d",&n,&k);
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    msort(arr,0,n-1);

     if(k>n/2)
     check=n-k;
     else
     check=k;
     for(j=0;j<check;j++)
     {
         sum_son=sum_son+arr[j];
     }

     for(;j<n;j++)
     {
         sum_dad=sum_dad+arr[j];
     }

      if(sum_dad-sum_son>0)
      printf("%d\n",sum_dad-sum_son);
      else
      printf("%d\n",sum_son-sum_dad);

      sum_dad=0;
      sum_son=0;
      cases--;


}
return 0;
}

