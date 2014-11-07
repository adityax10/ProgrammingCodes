#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	freopen("test.txt","r",stdin);
//		ios_base::sync_with_stdio(false);
	while(1)
	{
	
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		vector<vector<int> > A(n,vector<int>(m));
		vector<vector<int> > B(n,vector<int>(m));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>B[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>A[i][j];

		vector<vector<int> > suffixA(n,vector<int>(m+1)),prefixB(n,vector<int>(m+1));

		for(int i=0;i<n;i++)
		{
			prefixB[i][0]=B[i][0];
			for(int j=1;j<m;j++)
				prefixB[i][j]=B[i][j]+prefixB[i][j-1];
			
			suffixA[i][m-1]=A[i][m-1];
			for(int j=m-2;j>=0;j--)
				suffixA[i][j]=A[i][j]+suffixA[i][j+1];
		}
		
		vector<vector<int> > DP(n+1,vector<int>(m+1));
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<=m;j++)
				for(int k=j;k<=m;k++)
				{
					cout<<"Calculating for "<<i<<" "<<j<<endl;
					cout<<DP[i+1][k]<<" "<<suffixA[i][k]<<" ";
					int current=DP[i+1][k]+suffixA[i][k];
					if(k-1>=0)
					{
						current+=prefixB[i][k-1];
						cout<<prefixB[i][k-1];
						cout<<" "<<current;
					}
					cout<<endl;
					
					DP[i][j]=max(current,DP[i][j]);
				}
				
		for(int i=0;i<DP.size();i++)
		{
			for(int j=0;j<DP[i].size();j++)
				cout<<DP[i][j]<<"\t";
			cout<<endl;
		}

		cout<<DP[0][0];
	}
}
