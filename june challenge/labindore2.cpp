#include<stdio.h>
#include<string.h>

int partition(char a[],int l,int r)
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

void quicksort(char list[],int l,int r)
{
    if(r>l)
    {
    int q;
q=partition(list,l,r);
quicksort(list,l,q-1);
quicksort(list,q+1,r);
    }
}
int main()
{
    char arr[1000];
	int n,bar, i,j,test;
	scanf("%d",&test);
	
	while(test>0)
	{
	scanf("%s",arr);
	n=strlen(arr);
	if(n%2==1)
	bar=n/2+1;
	else
	bar=n/2;
    quicksort(arr,0,n/2-1);
    quicksort(arr,bar,n-1);
    i=0;j=bar;
  while((i<n/2)&&(j<=n-1))
  {
		if(arr[i]==arr[j])
		{
			i++;
			j++;
		}
		else
		{
		printf("NO\n");
		break;
	    }
    }
    
    if((j==n))
    {
        printf("YES\n");
    }
    test--;
}
    return 0;

}
