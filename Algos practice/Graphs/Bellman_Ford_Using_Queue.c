#include<stdio.h>
#include<limits.h>

int top=0,SIZE=10,prev=0;
void enqeue(int vertex[],int num)
{
    if((top+1)%SIZE!=prev)
    {
    top=(top+1)%SIZE;
    vertex[top]=num;
    }
    else{
        printf("NO Space avaliable!");
    }
}
int deqeue(int vertex[])
{
    if((prev!=top))
    {
        prev=(prev+1)%SIZE;
        printf("prev is %d\n",prev);
        return vertex[prev];
    }
    else{
        printf("No item to deqeue!\n");
    return -1;}
}

void bellman_ford(int a[][5],int dist[],int n,int s)
{	
	int i;
	int queue[10];
	for(i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[s]=0;
	
	//putting source in the queue
	enqeue(queue,s);
	
	while(top!=prev)//ie queue is not empty
	{
		int u = deqeue(queue);
		int v;
		for(v=0;v<n;v++)
		{
			if(v!=u && dist[u]!=INT_MAX && dist[v] > dist[u] + a[u][v])
			{
				dist[v] = dist[u] + a[u][v];
				enqeue(queue,v);
			}
		}
	}
	
	
	
}

int main()
{
   //int a[4][4]={{0,9,1,0},{9,0,3,7},{1,3,0,9},{0,7,9,0}};
  int a[5][5]=       {{0,1,4,2,99},
                    {1,0,99,3,7},
                    {4,99,0,1,1},
                    {2,3,1,0,1},
                    {99,7,1,1,0}};
   int n=5,i;
   int dist[5];

   bellman_ford(a,dist,n,0);

   for(i=0;i<n;i++)
   {
       printf("From source : %d distance of %d is  %d \n",0,i,dist[i]);
   }
   return 0;
}
