#include<iostream>
#include<cstdio>
using namespace std;


void swap(long long &x,long long &y)
{
    long z =x;
    x=y;
    y=z;
}

void max_heapify(long a[],int i,int n)
{
	int l=2*i;
	int r=2*i+1;
	int largest;

	if((l<=n)&& a[l]>a[i])
	largest=l;
	else
	largest=i;
	if((r<=n) && a[largest]<a[r])
	largest=r;
	
	if(largest!=i)
	{
	swap(a[largest],a[i]);
	//now mainting max heap property at the bottom heap of largest!
	max_heapify(a,largest,n);
    }
}

void build_max_heap(long a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n);
	}
}
void heap_sort(long a[],int n)
{
    build_max_heap(a,n);
	int N=n;
    //printf("Swapping and replacing......\n");
	for(int i=n;i>=2;i--)
	{
		swap(a[i],a[1]);
		n--;//excuding the last element from the heap cuz its the highest one in the available array
		max_heapify(a,1,n);
	}
}

long a[100000];

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif



inline long long readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
              c=GETCHAR();
              if(i==0&&c=='-') parity=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
              i++;
    }
    return parity*n;
}




int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif
	int n,negs;
	long long x,cost;
	
    n=readlong();
    for(int i=1;i<=n;i++)
    a[i]=readlong();
    x=readlong();
    
	heap_sort(a,n);
	negs=0;
	cost=0;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		negs++;
		else{
			break;
		}
   }
        //if x lies within
        if(x <= negs)
		{
				cost = x*(-a[x]);
				for(int i=1;i<x;i++)
				{
					cost += (-a[i]+a[x]);
			    } 
	    }
	    else
	    {
	    	for(int i=1;i<=negs;i++)
				{
					cost += (-a[i]);
			    }
	    }
	cout<<cost<<"\n";
}
