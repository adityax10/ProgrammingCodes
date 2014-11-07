#include<stdio.h>
#include<conio.h>

int mn;

int binsearch(int a[],int l,int r,int num)
{
   if(num%2==1)
   {
   mn=0;
   return search(a,l,r,num);
   }
   else
   {
	mn=1;
    return 	search(a,l+1,r,num);
   }

}

int search(int a[],int l,int r,int num)
{
	int mid;
	if(r<l)
	return -1;
	
	if(r-l==2)
	{
       //(a[r]==num)?(return r):((a[l]==num)?(return l):(return -1));
       if(a[r]==num)
       return r;
       else if(a[l]==num)
       return l;
       else
       return -1;
       
	}
	mid=(l+r)/2;
	
	if(mid%2==mn)
	mid++;
	
	if(num==a[mid])
	return mid;
	else if(num<a[mid])
	search(a,l,mid,num);
	else
	search(a,mid,r,num);
}

int main()
{
	int a[100],n,i,num;
	printf("Number of Elememts ?\n");
	scanf("%d",&n);
	printf("Enter the sorted array  where odd elements has odd position and even elements has even position both are sorted at their positions\n");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	printf("Enter the number to Search : ");
	scanf("%d",&num);
	i = binsearch(a,1,n,num);
	printf("%d",i);
     getch();
}
