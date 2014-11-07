#include<iostream>

#define SIZE 1000000
using namespace std;

int max(int x,int y)
{
    return x>y?x:y;
}

int max_profit;
long n,value[SIZE],size[SIZE],max_size;

int knapsack(int x/*present_size*/,int i,int cost)
{
	if(i>n+1)
	return 0;
	if(x==max_size)
	{
		max_profit = max(max_profit,cost);
	}
	knapsack(x+size[i],i+1,cost+value[i]);
	knapsack(x,i+1,cost);
	
}

int main()
{
    long i;
    cin>>n>>max_size;
    for(i=1;i<=n;i++)
    {
        cin>>value[i]>>size[i];
    }
    knapsack(0,1,0);
    if(max_profit==0)
    cout<<"Got caught!\n";
    else
    cout<<max_profit<<endl;
    
}
