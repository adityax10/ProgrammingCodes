#include<iostream>
#define MAX 999999
#define n 9
using namespace std;
void all_pair_shortestPath(int cost[][n],int dist[][n],int m);

int main()
{
    int cost[n][n]={{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},
                    {MAX,0,MAX,MAX,MAX,MAX,MAX,MAX,MAX},
                    {MAX,300,0,MAX,MAX,MAX,MAX,MAX,MAX},
                    {MAX,1000,800,0,MAX,MAX,MAX,MAX,MAX},
                    {MAX,MAX,MAX,1200,0,MAX,MAX,MAX,MAX},
                    {MAX,MAX,MAX,MAX,1500,0,250,MAX,MAX},
                    {MAX,MAX,MAX,MAX,1000,MAX,0,900,1400},
                    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,0,1000},
                    {MAX,1700,MAX,MAX,MAX,MAX,MAX,MAX,0}};
    int i,j,dist[n][n];
    
    cout<<"adjacency matrix for given graph is: \n( distance equal to '999999' means no direct edge and '0' represent vertex itself):\n\n";
    
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
        cout<<cost[i][j]<<"\t";
        }
        cout<<"\n";           
    }
    all_pair_shortestPath(cost,dist,n);
    cout<<"Shortest path matrix for given graph (999999 means that vertex is not reachable): \n";
    for(i=1;i<n;i++)  
    {
        for(j=1;j<n;j++)
        {
        cout<<dist[i][j]<<"\t";
        }
        cout<<"\n";
    }        
    return 0;
}

void all_pair_shortestPath(int cost[][n],int dist[][n],int m)
{
     int i,j,k;
     //INITIALSING ALL DIST TO WEIGHT OF EDGES
     for(i=1;i<m;i++)
     {
      for(j=1;j<m;j++)
      dist[i][j]=cost[i][j];
     }
     //CALCULATING THE SHORTEST LENGTHS OF EDGES
     for(k=1;k<m;k++)
     {
     	for(i=1;i<m;i++)
     	{
     		for(j=1;j<m;j++)
     		{
     		 //RELAXING THE EDGES
     		 if(dist[i][j]>(dist[i][k]+dist[k][j]))
             dist[i][j]=dist[i][k]+dist[k][j];
     		}
     	}
     }                                
}
