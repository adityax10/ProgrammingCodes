#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv) {
	
	int n,m;
	cin>>n>>m;
	
	bool visited[101][101];
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		visited[i][j]=0;
	}
	visited[0][0]=1;
	int count =0;
	char f = 'E';
	int moves=1;
	int i=0,j=0;
	while(1)
	{
		if(count==4)
		break;
		// E
		if(f=='E' && j+1<m && visited[i][j+1]==0)
		{
			moves++;
			visited[i][j+1]=1;
			f='S';
			j++;
			count=0;
			continue;
		}
		else if(f=='E')
		{
			count++;
			f='S';
			continue;
		}
		
		// S
		if(f=='S' && i+1<n && visited[i+1][j]==0)
		{
			moves++;
			visited[i+1][j]=1;
			f='W';
			i++;
			count=0;
			continue;
		}
		else if(f=='S')
		{
			count++;
			f='W';
			continue;
		}
		
		// W
		if(f=='W' && j-1>=0 && visited[i][j-1]==0)
		{
			moves++;
			visited[i][j-1]=1;
			f='N';
			j--;
			count=0;
			continue;
		}
		else if(f=='W')
		{
			count++;
			f='N';
			continue;
		}
		
		// N
		if(f=='N' && i-1>=0 && visited[i-1][j]==0)
		{
			moves++;
			visited[i-1][j]=1;
			f='E';
			i--;
			count=0;
			continue;
		}
		else if(f=='N')
		{
			count++;
			f='E';
			continue;
		}	
	}
	cout<<moves<<endl;
	return 0;
}

