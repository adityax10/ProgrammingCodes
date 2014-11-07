#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define REDIRECT_IO

int maze[101][101];

int cal_ans(int n,int m)
{
	int val[n][m];
	bool cfl[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		val[i][j]=maze[i][j];
	}
	val[0][0]+=val[0][1]+val[1][0];
	cout<<val[0][0]<<" ";
	for(int i=1;i<m;i++) //Col 0
	{
	val[0][i]=val[1][i]+val[0][i-1] + (((i+1)<m )? val[0][i+1]:0);
	cfl[0][i]=1;
	cout<<val[0][i]<<" ";
    }
	cout<<endl;
	for(int i=1;i<n;i++) //Row 0
	{
	if(maze[i][0]==1)
	val[i][0]=val[i-1][0]+val[i][1] + (((i+1)<n )? val[i+1][0]:0);
	else
	val[i][0]+=val[i-1][0]+val[i][1] + (((i+1)<n )? val[i+1][0]:0);  
	cfl[i][0]=0;
	cout<<val[i][0]<<" ";
    }
	cout<<endl;
	

	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			/*if(i== 2 && j==4 )
			{
				cout<<" top "<<cfl[i-1][j]<<" left "<<cfl[i][j-1]<<endl;
				cout<<val[i-1][j]<<" "<<val[i][j-1]<<endl;
			}*/
			if(val[i-1][j] < val[i][j-1])
			{
				if(cfl[i-1][j]==1)
				{
					val[i][j] = val[i-1][j] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				else
				{
					val[i][j] = val[i-1][j]+ maze[i][j-1] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				cfl[i][j]=0;
			}
			else if(val[i-1][j] > val[i][j-1])
			{
			/*	if(i== 1 && j==3)
				cout<<"C\n";*/
				if(cfl[i][j-1]==1)
				{
					val[i][j] = val[i][j-1] + maze[i-1][j] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				else
				{
					val[i][j] = val[i][j-1]+ ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				cfl[i][j]=1;
			}
			else
			{
				int x,y ;
				//top
				if(cfl[i-1][j]==1)
				{
					x= val[i-1][j] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				else
				{
					x = val[i-1][j]+ maze[i][j-1] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				//left
				if(cfl[i][j-1]==1)
				{
					y = val[i][j-1] + maze[i-1][j] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				else
				{
					y=val[i][j-1] + ((i+1<n)? maze[i+1][j]:0) + ((j+1<m)? maze[i][j+1]:0);
				}
				val[i][j]=min(x,y);
				if(x>y)
				cfl[i][j]=0;
				else
				cfl[i][j]=1;
			}
			cout<<val[i][j]<<" ";
		}
		cout<<endl;
	}

	return val[n-1][m-1];
}

int main()
{
	#ifdef REDIRECT_IO
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
	string s;
	int cases;
//	scanf("%d",&cases);
	cin>>cases;
	while(cases--)
	{
		int n,m;
		//scanf("%d",&n);
		//scanf("%d",&m);
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
			{
			maze[i][j]=s[j]-48;
		    }   
			//scanf("%d",&maze[i][j]);
		}
		//printf("%d\n",cal_ans(n,m));
		cout<<cal_ans(n,m)<<endl;
	}
	return 0;
}


