#include<stdio.h>
#include<limits.h>

int bellman_ford(int a[][5],int dist[],int n,int s)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[s]=0;

    //computing shortest paths with min edges
	for(k=0;k<n;k++)
	{
		//for each edge in graph,Relax the edge
		//as k increases, the no of intermediate edges b/w vetex i and vertex j will also increase
		for(i=0;i<n;i++)
		{
		    //printf("i = %d\n",i);
			for(j=0;j<n;j++)
			{
				if(dist[i] == INT_MAX || a[i][j]==0)
				continue;
	
				if(dist[j] > dist[i] + a[i][j])
				{
				    //printf("Relaxing %d n %d\n",i,j);
					dist[j]=dist[i]+ a[i][j];
				}
			}
	
		}
   }
   
   //Checking for cyles of -ve weight
   for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++)
		{
			if(dist[j] > dist[i] + a[i][j])
			{
			   printf("Cycles Exsist !!\nCannt be done USing Bellman Ford!!\n");
			   return 0;
			}
		}
   }
		
   return 1;
}

int main()
{
   //int a[4][4]={{0,9,1,0},{9,0,3,7},{1,3,0,9},{0,7,9,0}};
  int a[5][5]=       {{0,6,0,0,7},
                    {0,0,5,-4,8 },
                    {0,-2,0,0,0},
                    {2,0,7,0,0},
                    {0,0,-3,9,0}};
    
   int n=5,i;
   int dist[5];

   if(bellman_ford(a,dist,n,0)==1)
   {
   for(i=0;i<n;i++)
   {
       printf("From source : %d distance of %d is  %d \n",0,i,dist[i]);
   }
}
   return 0;
}

