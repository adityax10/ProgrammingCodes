#include <bits/stdc++.h>

using namespace std;

int a[302][302];
bool visited[302][302];
int v[302][302];

void cal(int i,int j,int n)
{
	if(visited[i][j])
	return ;
	else if(a[i][j]==1 || i>=n || j>=n || i<0 || j<0)
	return ;
	else if(v[i][j]==0)
	{
		cout<<"Visit "<<i<<" "<<j<<endl;
		visited[i][j]=1;
		
		cal(i-1,j-1,n);
		cal(i-1,j,n);
		cal(i-1,j+1,n);
		
		cal(i,j-1,n);
		cal(i,j+1,n);
		
		cal(i+1,j-1,n);
		cal(i+1,j,n);
		cal(i+1,j+1,n);
	}
	else
	{
		visited[i][j]=1;
		
		visited[i-1][j-1]=1;
		visited[i-1][j]=1;
		visited[i-1][j+1]=1;
		visited[i][j-1]=1;
		visited[i][j+1]=1;
		visited[i+1][j-1]=1;
		visited[i+1][j]=1;
		visited[i+1][j+1]=1;
		return;
	}
	
}

int cal_clicks(int n)
{
	int clicks = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		visited[i][j]=0 , v[i][j]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				v[i][j] =  a[i][j+1] +
						   a[i+1][j]+a[i+1][j+1]; 
			}
			else if(i==0)
			{
				v[i][j] = a[i][j-1] + a[i][j+1] +
							a[i+1][j-1]+a[i+1][j]+a[i+1][j+1]; 
			}
			else if(j==0)
			{
				v[i][j] = a[i-1][j] + a[i-1][j+1] +
						 a[i][j+1] +
							a[i+1][j]+a[i+1][j+1];  
			}
			else if(i > 0 && i<= n-2 && j>0 && j<=n-2)
			{
				v[i][j] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] +
							a[i][j-1] + a[i][j+1] +
							a[i+1][j-1]+a[i+1][j]+a[i+1][j+1]; 
			}
		}	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!visited[i][j] && a[i][j]!=1 && v[i][j]==0)
			{
				cout<<"Inc at "<<i<<" "<<j<<endl;
				cal(i,j,n);
				clicks++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!visited[i][j] && a[i][j]!=1)
			{
				cout<<"Inc at "<<i<<" "<<j<<endl;
				cal(i,j,n);
				clicks++;
			}
		}
	}
	return clicks;
}

int main(int argc, char** argv) {
	freopen("in1.txt","r",stdin);
	int cases,_n=0;
	cin>>cases;
	while(cases--)
	{
		_n++;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				char x;
				cin>>x;
				a[i][j] = x;
				if(a[i][j]=='*')
				a[i][j] = 1;
				else
				a[i][j]=0;
			}
		}
			
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
		cout<<"Case #"<<_n<<" "<<cal_clicks(n)<<endl;
	}
	return 0;
}

