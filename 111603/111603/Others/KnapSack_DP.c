#include<stdio.h>
#include<conio.h>

#define SIZE 100
int maxsize=50;

int max(int x,int y)
{
    return x>y?x:y;
}

int knapsack(int size[],int value[],int x/*present_size*/,int i,int n)
{
    if(x<maxsize){
    printf("Present Size  is %d n i=%d \n",x,i);
    getch();

   if(i==n)
   {
     if(size[i]<maxsize-x)
     return value[i];
     else
     return -value[i];
   }

     return max(knapsack(size,value,x,i+1,n),knapsack(size,value,x+size[i],i+1,n));
    }
    //return 0;

}

int main()
{
    int i,n,value[SIZE],size[SIZE],maxsize;
    printf("Enter the Number of Items in the list : ");
    scanf("%d",&n);
    printf("Enter the Size And Vaue For each item\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&size[i],&value[i]);
    }
    //printf("Enter the MAXIMUM SIZE : ");
    //scanf("%d",&maxsize);

    knapsack(size,value,0,1,n);
}
