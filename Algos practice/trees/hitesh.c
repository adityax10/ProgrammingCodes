#include<stdio.h>

int* shortestpath(int v,int cost[][5],int dist[],int n)
{
                 int i,j,num,min=99999,s[5],u,w;
      for(i=1;i<n;i++)
      {
                      s[i]=0;
                      dist[i] = cost[v][i];
      }
      s[v]=1; dist[v]=0;
      for(num=2;num<=n;num++)
      {
         for(u=2;u<=n;u++)
         {
            while( (min>cost[v][u]) && s[u]==0)
            min=cost[v][u];
            //break;
         }
         s[u]=1;
         dist[u]=min;
         for(w=2;w<=n;w++)
         {
            if(s[w]==0 && cost[u][w]!=0 && cost[u][w]!=99)
            if(dist[w]>(dist[u] +  cost[u][w]))
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
                 {99,7,1,1,0}},n=5,dist[5],i;
    shortestpath(0,cost,dist,n);
    for(i=0;i<n;i++)
    printf("%d ",*(dist+i));
    //getch();
    return 0;
}

