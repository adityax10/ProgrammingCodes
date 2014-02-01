#include<stdio.h>
#include<conio.h>
#define MAX 100000
#define n 9

int prim(int cost[][9],int t[][2],int m);

int main()
{
    int cost[n][n]={{MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX},
                    {MAX,MAX,11,13,MAX,2,MAX,MAX,MAX},
                    {MAX,11,MAX,15,8,12,MAX,6,MAX},
                    {MAX,13,15,MAX,MAX,MAX,MAX,MAX,MAX},
                    {MAX,MAX,8,MAX,MAX,14,10,MAX,17},
                    {MAX,2,12,MAX,14,MAX,MAX,MAX,5},
                    {MAX,MAX,MAX,MAX,10,MAX,MAX,21,7},
                    {MAX,MAX,6,MAX,MAX,MAX,21,MAX,11},
                    {MAX,MAX,MAX,MAX,17,5,7,11,MAX}};
    int i,t[n][2],mincost;
    mincost=prim(cost,t,n);
    printf("edges of minimum cost spanning tree are( in order of selection) :\n");
    for(i=1;i<(n-1);i++)
                    printf("%d <--> %d\n",t[i][0],t[i][1]);
    printf("\nminimum cost: %d",mincost);
    getch();
    return 0;
}

int prim(int cost[][9],int t[][2],int m)
{
    int i,j,temp=MAX,k,l,near[m],mincost=0;
    //Finding MinEdge For Starting the Approach
    for(i=1;i<m;i++)
    {
	    for(j=1;j<m;j++)
	    if(cost[i][j]<temp)
	    {
	       temp=cost[i][j];
	       k=i;
	       l=j;
	    }
    }
    //saving the vertices corresponding to Min Edge
    t[1][0]=k;
    t[1][1]=l;
    mincost+=cost[k][l];
    // Initilalise near wrt to l and k for all the vertices
    for(i=1;i<m;i++)
    {
        if(cost[i][k]<cost[i][l])
         near[i]=k;
        else
        near[i]=l;
    }
    near[k]=near[l]=0; //Since l and k have been considered
    
    //now calculating for other edges
    for(i=2;i<(m-1);i++) 
    {
	    temp=MAX;
	    // calculating min edge
	    for(j=1;j<n;j++)
	    {
	        if((near[j]!=0)&&(cost[j][near[j]]<temp))
	        {
	         temp=cost[j][near[j]];
	         l=j;
	         k=near[j];
	        }
	    }
	    //including min edge in ans
	    t[i][0]=k;
	    t[i][1]=l;
	    mincost+=cost[k][l];
	    
	    near[l]=0;
	    //updating near for next cycle
	    for(j=1;j<m;j++)
	    {
	    if((near[j]!=0)&&(cost[j][near[j]]>cost[l][j]))
	    near[j]=l;
	    }
    }
    return mincost;
}
