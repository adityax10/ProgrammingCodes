#include<iostream>
#define SIZE 4

using namespace std;

void print_sol(int color[])
{
    for(int i=0;i<SIZE;i++)
    cout<<color[i]<<" ";
    cout<<"\n";
}

bool canColor(int i,int c,int color[],int g[][SIZE])
{
    for(int j=0;j<SIZE;j++)
    {
    	//Edge exists with vetex j and has been coloured with the same color as vetex i
        if(g[i][j]>0 && color[j]==c)
        return false;
    }
    return true;
}

void mGraphColor(int i,int color[],int g[][SIZE])
{
    if(i==SIZE)
    {
        print_sol(color);
        return;
    }
    //Colouring the ith Vertex
    //ith vertex, jth color
    for(int j=0;j<4;j++)
    {
        //if vertex hasn't been coloured yet
        if(color[i]==-1 && canColor(i,j,color,g))
        {
            color[i]=j;
            mGraphColor(i+1,color,g);
            color[i]=-1;//Backtracking
        }
    }
}

int main()
{
    int g[SIZE][SIZE]={{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int color[SIZE];
    for(int i=0;i<SIZE;i++)
    color[i]=-1;
    mGraphColor(0,color,g);
}
