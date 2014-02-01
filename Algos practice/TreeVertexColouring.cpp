#include<iostream>

using namespace std;

#define SIZE 5

int RED=1,GREEN=2,BLUE=3,YELLOW=4;

bool okToColor(int i,int color,int matrix[][SIZE],int vertexColor[SIZE])
{
	for(int j=0;j<SIZE;j++)
	{
		if(matrix[i][j]!=0)
		{
			if(vertexColor[j]==color)
			{
				return false;
			}
	   }
	}
	return true;
}

//i => vertex
void graphColor(int matrix[][SIZE],int vertexColor[SIZE],int i,int color)
{
	if(i==SIZE)
	{
		for(int i=0;i<SIZE;i++)
		{
			cout<<vertexColor[i];
		}
		cout<<endl;
		return;
    }
	if(okToColor(i,color,matrix,vertexColor))
	{
		vertexColor[i]=color;
		for(int c=RED;c<=YELLOW;c++)
		{
			graphColor(matrix,vertexColor,i+1,c);
		}
    }
}

int main()
{
	int adjMatrix[SIZE][SIZE]={{0,1,1,0,0},{1,0,1,1,1},{1,1,0,1,0},{0,1,1,0,1},{0,1,0,1,0}};
	//vertexColor[i] => stores color for ith vertex 
	int vertexColor[SIZE];
	graphColor(adjMatrix,vertexColor,0,1);
}
