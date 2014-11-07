#include<iostream>
#define SIZE 5

int visited[SIZE];

using namespace std;

void print_sol()
{
	for(int i=0;i<SIZE;i++)
	cout<<visited[i]<<" ";
	cout<<"\n";
}

bool can_include(int x)
{
	for(int i=0;i<SIZE;i++)
	{
		if(visited[i]==x)
		return 0;
	}
	return 1;
}

void create_path(int i,int processed,int g[][SIZE])
{	
	if(processed == SIZE)
	{
		if( g[visited[0]][visited[processed-1]] !=0)
	    print_sol();
	    return;
    }
    
	if(processed >SIZE)
	return ;
	
	for(int j=0;j<SIZE;j++)
	{
		//cout<<"For i = "<<i<<" Checking for j ="<<j<<endl;
		if( g[i][j]!=0 && can_include(j))
		{
			//cout<<"Selected "<<j<<endl;
			visited[processed]=j;
			create_path(j,processed+1,g);
			visited[processed]=-1; // BACKTRACKING
		}
	}
}

void halmitonial_path(int n,int g[][SIZE])
{
	for(int i=0;i<SIZE;i++)
	{
		visited[0]=i;
		create_path(i,1,g);
		visited[0]=-1;
	}
}

int main()
{
	int n;
	int g [SIZE][SIZE]= {{0,1,0,2,99},
                        {1,0,99,3,7},
                        {0,99,0,1,1},
                        {2,3,1,0,1},
                        {99,7,1,1,0}};
	for(int i=0;i<SIZE;i++)
	visited[i]=-1;
	halmitonial_path(SIZE,g);
	
}
