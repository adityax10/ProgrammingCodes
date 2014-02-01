#include<stdio.h>
#include<limits.h>

int* shortestpath(int v,int cost[][5],int dist[],int n)
{
                 int i,j,num,min,s[5],u,w,min_u=0;
      for(i=0;i<n;i++)
      {
                      s[i]=0;
                      dist[i] = cost[v][i];
      }
      s[v]=1; dist[v]=0;
      for(num=1;num<n;num++)
      { 
      	min=99999;
         for(u=1;u<n;u++)
         {
            if(min>cost[v][u]&& s[u]==0)
            {
            min=cost[v][u];
            min_u=u;
            }
         }
         printf("Min found iss %d\n",min_u);
         s[min_u]=1;
         dist[u]=min;
         for(w=1;w<n;w++)
         {
            if(s[w]==0 && cost[u][w]!=0 && cost[u][w]!=99)
            if(dist[w] > (dist[u] +  cost[u][w]))
            dist[w]=dist[u]+cost[u][w];
         }
      }
      return dist;

}
int main()
{
    int cost[5][5]={{0,1,4,2,99},
                    {1,0,99,3,7},
                    {4,99,0,1,1},
                    {2,3,1,0,1},
                    {99,7,1,1,0}};
					int n=5,dist[5],i;
    shortestpath(0,cost,dist,n);
    printf("n = %d",n);
    for(i=0;i<5;i++)
    printf("%d \n",dist[i]);
    //getch();
    return 0;
}

