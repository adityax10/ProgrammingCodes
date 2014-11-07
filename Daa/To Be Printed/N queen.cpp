#include<iostream>
#include<cmath>
#define SIZE 8
int ans;

using namespace std;

void printBoard(bool board[][SIZE])
{
	for(int  x=0;x <SIZE;x++)
	{
		for(int y=0;y<SIZE;y++)
		{
			cout<<board[x][y]<<" ";
		}
		cout<<"\n";
	}
}

bool canPlace(int x,int y,bool board[][SIZE],int n) //x=>Queen Row , y=>Queen Column
{
	if(n<=0)
	return 0;
	//cout<<"Checking place for x ="<<x<<" and y"<<y<<"\n";
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(board[i][j]==1)
			{
			    //cout<<"Queen found at "<<i<<" "<<j<<"\n"; 
				if((abs(x-i) == abs(y-j))) // Diagonally Cutting 
				{
					return 0;
				}
				else if(y==j) //columns are same
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int NQueen(int i,bool board[][SIZE],int n)
{
    //printBoard(board);
	//cout<<"Finding for i ="<<i<<" and n ="<<n<<"\n";
	if(i==SIZE)
	{
		ans++;
	}
	if(i>SIZE)
	return 0;
	
	if(n==0)
	return 0;
	
	for(int j=0;j<SIZE;j++)
	{
		if(canPlace(i,j,board,n))
		{
		board[i][j]=1;
	    NQueen(i+1,board,n);
	    board[i][j]=0; //Backtracking
	    }
    }
	//printBoard(board);
}

int main()
{
	int n;
	bool board [SIZE][SIZE];
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		board[i][j]=0;
	}
	//cout<<"Enter the Size of Board : \n";
	//cin>>n;
	NQueen(0,board,SIZE);
	cout<<ans;
}
