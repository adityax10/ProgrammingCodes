#include <bits/stdc++.h>
#define max 25
using namespace std;


int c = 1;

int cal(int n,int a[][max],string dir)
{
	if(dir=="up")
	{
		for(int j=0;j<n;j++)
		{
			bool found = 0;
			int to_find;
			//finding
			for(int i=0;i<n;i++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(!found)
				{
					to_find = i;
					found =1;
				}
				else if(found && a[i][j]==a[to_find][j])
				{
					a[to_find][j]*=2;
					a[i][j]=0;
					found=0;
				}
				else if(found && a[i][j]!=a[to_find][j])
				{
					to_find = i;
				}
			}
			
		
			int zeros[n];
			zeros[0]= (a[0][j]==0);
			for(int i=1;i<n;i++)
			{
				zeros[i]=zeros[i-1];
				if(a[i][j]==0)
				zeros[i]++;
			}
			
			
			// shifting
			for(int i=0;i<n;i++)
			{
				if(a[i][j]==0)
				continue;
				else if(zeros[i]!=0)
				{
					a[i-zeros[i]][j] = a[i][j];
					a[i][j]=0;
				}
			}
	
		}
	}
	else if(dir=="down")
	{
		for(int j=0;j<n;j++)
		{
			bool found = 0;
			int to_find;
			//finding
			for(int i=n-1;i>=0;i--)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(!found)
				{
					to_find = i;
					found =1;
				}
				else if(found && a[i][j]==a[to_find][j])
				{
					a[to_find][j]*=2;
					a[i][j]=0;
					found=0;
				}
				else if(found && a[i][j]!=a[to_find][j])
				{
					to_find = i;
				}
			}
			
		
			int zeros[n];
			zeros[n-1]= (a[n-1][j]==0);
			for(int i=n-2;i>=0;i--)
			{
				zeros[i]=zeros[i+1];
				if(a[i][j]==0)
				zeros[i]++;
			}
			
		
			// shifting
			for(int i=n-1;i>=0;i--)
			{
				if(a[i][j]==0)
				continue;
				else if(zeros[i]!=0)
				{
					a[i+zeros[i]][j] = a[i][j];
					a[i][j]=0;
				}
			}
		
		}
	}
	else if(dir=="right")
	{
		for(int i=0;i<n;i++)
		{
			bool found = 0;
			int to_find;
			
			//finding
			for(int j=n-1;j>=0;j--)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(!found)
				{
					to_find = j;
					found =1;
				}
				else if(found && a[i][j]==a[i][to_find])
				{
					a[i][to_find]*=2;
					a[i][j]=0;
					found=0;
				}
				else if(found && a[i][j]!=a[i][to_find])
				{
					to_find = j;
				}
			}
	
			
			int zeros[n];
			zeros[n-1]= (a[i][n-1]==0);
			
			for(int j=n-2;j>=0;j--)
			{
				zeros[j]=zeros[j+1];
				if(a[i][j]==0)
				zeros[j]++;
			}
			
			
			// shifting
			for(int j=n-1;j>=0;j--)
			{
				if(a[i][j]==0)
				continue;
				else if(zeros[j]!=0)
				{
					a[i][j+zeros[j]] = a[i][j];
					a[i][j]=0;
				}
			}
		
		}
	}
	else if(dir=="left")
	{
		for(int i=0;i<n;i++)
		{
			bool found = 0;
			int to_find;
			
			//finding
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(!found)
				{
					to_find = j;
					found =1;
				}
				else if(found && a[i][j]==a[i][to_find])
				{
					a[i][to_find]*=2;
					a[i][j]=0;
					found=0;
				}
				else if(found && a[i][j]!=a[i][to_find])
				{
					to_find = j;
				}
			}
			
		
			
			int zeros[n];
			zeros[0]= (a[i][0]==0);
			
			for(int j=1;j<n;j++)
			{
				zeros[j]=zeros[j-1];
				if(a[i][j]==0)
				zeros[j]++;
			}
			
			
			
			// shifting
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==0)
				continue;
				else if(zeros[j]!=0)
				{
					a[i][j-zeros[j]] = a[i][j];
					a[i][j]=0;
				}
			}
		
		}
	}
	cout<<"Case #"<<c<<":"<<endl;
	c++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(int argc, char** argv) 
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);	
	int cases;
	cin>>cases;
	int n;
	string dir;
	int a[max][max];
	while(cases--)
	{
		cin>>n>>dir;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		cal(n,a,dir);
	}
	
	return 0;
}

