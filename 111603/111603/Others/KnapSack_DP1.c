#include<stdio.h>
//#include<conio.h>

#define SIZE 100
int maxsize=7;

int max(int x,int y)
{
    return x>y?x:y;
}

int knapsack(int size[],int value[],int x/*present_size*/,int i,int n)
{
    if(x==maxsize)
    {
		  return 0;
    }

   if(i==n)
   {
     if(size[i]<=maxsize-x)
     return value[i];
     else
     return 0;
   }
     if(size[i]<=maxsize-x)
     {
     //printf("Finding max for i = %d\n",i);
     return max(knapsack(size,value,x+size[i],i+1,n)+value[i],knapsack(size,value,x,i+1,n));
	 }
	 else
	 knapsack(size,value,x,i+1,n);
     
}

int main()
{
    int i,n,value[SIZE],size[SIZE],maxsize;
    printf("Enter the Number of Items in the list : ");
    scanf("%d",&n);
    printf("Enter the Size And Vaue For each item in incresing order of their value\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&size[i],&value[i]);
    }
    
    //printf("Enter the MAXIMUM SIZE : ");
    //scanf("%d",&maxsize);

    printf("MAximum Value is : %d",knapsack(size,value,0,1,n));
    while(1)getchar();
}
