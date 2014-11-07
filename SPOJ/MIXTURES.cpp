#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


int cal_dp(vector<int> A)
{
	int n = A.size();
 	vector< vector < vector<int> > >  a( n , vector<vector<int> > (n, vector<int>(n))  );
	vector<vector<int> >  c(n,vector<int> (n-1));
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
		c[i][j]=0;
			
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		a[i][j][0] = A[i]; 
	}
	
	for(int k=1;k<n-1;k++)
	{	
		cout<<"Stage : "<<k<<endl;
		for(int i=0;i<n-1;i++)
		{
			a[i][k]=(a[i][k-1]+a[i+1][k-1])%100;
			c[i][k] += a[i][k-1] * a[i+1][k-1];
			
			//print
			for(int i=0;i<n;i++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		k++;
	}
	
	int min_c = INT_MAX;
	for(int i=0;i<n-1;i++)
	min_c = min(min_c , c[i][n-2]);
	return min_c;
}

int main()
{
	freopen("inMIX.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> a(n);
	int i=0;
	while(i<n)
	cin>>a[i++];
	cout<<cal_dp(a);
	return 0;
}


