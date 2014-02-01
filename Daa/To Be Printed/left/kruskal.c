#include<stdio.h>
#include<conio.h>
#define MAX 100000
#define n 9

int kruskal(int cost[][9],int t[][2],int m);
int find(int i,int parent[]);
void union1(int i,int j,int parent[]);
int delete1(int arr[][3],int y);
void heapify(int arr[][3],int y);
void adjust(int ar[][3],int m,int y);
void swap(int *a,int *b);

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
    mincost=kruskal(cost,t,n);
    if(mincost==-1)
                   printf("No spanning tree is possible from given graph");
    else
    {
        printf("edges of minimum cost spanning tree are( in order of selection) :\n");
        for(i=1;i<(n-1);i++)
                            printf("%d <--> %d\n",t[i][0],t[i][1]);
        printf("\nminimum cost: %d",mincost);
    }
    getch();
    return 0;
}

void swap(int *a,int *b)
{
                    int c;
                    c=*a;
                    *a=*b;
                    *b=c;
}

int kruskal(int cost[][9],int t[][2],int m)
{
    int parent[m],i,j,x=0,a[81][3],mincost=0,y,k,l,z=m;
    for(i=1;i<m;i++)
    {
                    for(j=1;j<m;j++)
                    {
                                    if(cost[i][j]!=MAX)
                                    {
                                                    a[x][0]=cost[i][j];
                                                    a[x][1]=i;
                                                    a[x][2]=j;
                                                    x++;
                                    }
                    }
    }
    heapify(a,x);
    for(i=1;i<m;i++)
                    parent[i]=-1;
    i=0;
    y=x;
    while((y>0)&&(i<(z-2)))
    {
                            y=delete1(a,y);
                            k=find(a[y][1],parent);
                            l=find(a[y][2],parent);
                            if(k!=l)
                            {
                                    i++;
                                    t[i][0]=a[y][1];
                                    t[i][1]=a[y][2];
                                    mincost+=cost[a[y][1]][a[y][2]];
                                    union1(k,l,parent);
                            }
    }
    if(i!=(z-2))
              return -1;
    else
        return mincost;                       
}   

int find(int i,int parent[])
{
    while(parent[i]>=0)
                       i=parent[i];
    return i;
}

void union1(int i,int j,int parent[])
{
    parent[i]=j;
}

int delete1(int arr[][3],int x)
{
    int y;
    y=x-1;
    if(y>=0)
    {
               swap(&arr[0][0],&arr[y][0]);
               swap(&arr[0][1],&arr[y][1]);
               swap(&arr[0][2],&arr[y][2]);
               y--;
               adjust(arr,0,y);
    }
    return y+1;
}

void heapify(int arr[][3],int y)
{
     int i,x;
     x=y-1;
     for(i=((x-1)/2);i>=0;i--)
                       adjust(arr,i,x);
}
   
void adjust(int ar[][3],int m,int y)
{
    if(((2*m+1)<=y)&&((2*m+2)<=y))
    {        
                            if((ar[m][0]>ar[(2*m+1)][0])&&(ar[(2*m+2)][0]>=ar[(2*m+1)][0]))
                            {
                                                                 swap(&(ar[m][0]),&(ar[(2*m+1)][0]));
                                                                 swap(&(ar[m][1]),&(ar[(2*m+1)][1]));
                                                                 swap(&(ar[m][2]),&(ar[(2*m+1)][2]));
                                                                 adjust(ar,(2*m+1),y);
                            }
                            if((ar[m][0]>ar[(2*m+2)][0])&&(ar[(2*m+1)][0]>ar[(2*m+2)][0]))
                            {
                                                                   swap(&(ar[m][0]),&(ar[(2*m+2)][0]));
                                                                   swap(&(ar[m][1]),&(ar[(2*m+2)][1]));
                                                                   swap(&(ar[m][2]),&(ar[(2*m+2)][2]));
                                                                   adjust(ar,(2*m+2),y);
                            }
    }           
    else if((2*m+1)<=y)
    {            
                  if(ar[m][0]>ar[(2*m+1)][0])
                  {
                                  swap(&(ar[m][0]),&(ar[(2*m+1)][0]));
                                  swap(&(ar[m][1]),&(ar[(2*m+1)][1]));
                                  swap(&(ar[m][2]),&(ar[(2*m+1)][2]));
                  }
    }            
}
