#include<stdio.h>
#include<limits.h>

void shortest_path(int a[][5],int dist[],int n,int s)
{
    int i,visited[n];
    int min=INT_MAX,visited_nodes=0;
    for(i=0;i<n;i++)
    {
      dist[i]=INT_MAX;
      visited[i]=0;
    }
    dist[s]=0;
    //visited[s]=1;
    //now selecting min edge from each time
    while(1)
    {
    min =INT_MAX;
      for(i=0;i<n;i++)
      {
          if(min > dist[i] && visited[i]==0)
          {
          min=i;
          }
      }
     // printf("Selected min is : %d \n",min);

      visited[min]=1;
      visited_nodes++;

      for(i=0;i<n;i++)
      {
          if(i==min)
          continue;
          if(a[min][i]!=0)
          {
          int x = a[min][i]+dist[min];
          dist[i] = (dist[i]>x)?x:dist[i];
          }
      }
      if(visited_nodes == n)
      {
          break;
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

   shortest_path(a,dist,n,0);

   for(i=0;i<n;i++)
   {
       printf("From source : %d distance of %d is  %d \n",0,i,dist[i]);
   }
}
