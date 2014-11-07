#include<iostream>
#include<cmath>
using namespace std;

#define SIZE 8

void printBoard(int x[])
{
	for(int i=0;i<SIZE;i++)
	cout<<x[i]<<" ";
	cout<<"\n";
}

bool canPlace(int x,int y,int col_occupied[])
{
	//cout<<"Checking place for x ="<<x<<" and y"<<y<<"\n";
	
	for(int i=0;i<x;i++)
	{
		int j=col_occupied[i];
		if(abs(x-i)==abs(y-j) || i==j)
		{
			cout<<"Cancelling\n";
			return 0;
		}
	}
	return 1;
}
int ans;

//ith queen
//SIZE total queens
int NQueen(int i,int col_occupied[])
{
	printBoard(col_occupied);
	if(i==SIZE)
	{
		ans++;
	}
	if(i<0 || i>=SIZE)
	return 0;
	int d;
	cin>>d;
	
	//j => column
	for(int j=0;j<SIZE;j++)
	{
		if(canPlace(i,j,col_occupied) && col_occupied[i]==-1)
		{
		col_occupied[i]=j;
	    NQueen(i+1,col_occupied);
	    col_occupied[i]=-1;//Backtracking
	    //n++;
	    }
    }
	//printBoard(board);
	
}

int main()
{
	int n;
	int col_occupied[SIZE];
	for(int i=0;i<SIZE;i++)
	{
		col_occupied[i]=-1;
	}
	//cout<<"Enter the Size of Board : \n";
	//cin>>n;
	NQueen(0,col_occupied);
	cout<<"\n"<<ans;
}
