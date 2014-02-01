#include<stdio.h>
void main()
{
 unsigned long long a[100];
 int i,j,k,count=0;
 scanf("%d",&i);
 for(j=0;j<i;j++)
 {
    scanf("%d",&a[j]);
 }
 scanf("%d",&k);
 for(j=0;j<i;j++)
{
    if(a[j]<a[k-1])
    {
     printf("%d greater than %d\n",a[k-1],a[j]);
     count++;
    }
}

printf("%d",count+1);
}
