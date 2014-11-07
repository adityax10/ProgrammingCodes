//p[] => probabiltiy of presence of ith node
//q[] => probaility of presence of ith node in equivalence class

#include<iostream>
#include<limits.h>

#define SIZE 5

using namespace std;

void OBST(double p[],double q[],int n)
{
	double w[SIZE+1][SIZE+1];
	int r[SIZE+1][SIZE+1];
	double c[SIZE+1][SIZE+1];
	
	//Initialising 
	for(int i=0;i<n-1;i++)
	{
		w[i][i]=q[i];
		r[i][i]=0;
		c[i][i]=0;
		
		w[i][i+1]=w[i][i]+p[i+1]+q[i+1];
		c[i][i+1]=w[i][i+1];
		r[i][i+1]=i+1;
	}
	
	w[n-1][n-1]=q[n-1];r[n-1][n-1]=0;c[n-1][n-1]=0;
	
	for(int m=2;m <n;m++)
	{
		for(int i=0;i<n-m;i++)
		{
			int j=i+m;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			
			//finding k
			int min_k=r[i][j-1],k;
			
			for(k=r[i][j-1];k<r[i+1][j];k++)
			{
				if(c[i][k-1]+c[k][j]+w[i][j] < c[i][j])
				{
					c[i][j]=(c[i][k-1]+c[k][j]+w[i][j]);
					min_k=k;
				}
			}
			c[i][j]=w[i][j]+c[i][min_k-1]+c[min_k][j];
			r[i][j]=k;
		}
	}
	cout<<"Root is :"<<r[0][n-1]<<endl;
	cout<<"Cost is  :"<<c[0][n-1]<<endl;
	
}

using namespace std;

int main()
{
	double p[SIZE]={0.15,0.10,0.05,0.10,0.20};
	double q[SIZE+1]={0.05,0.10,0.05,0.05,0.05,0.10};
	
	OBST(p,q,SIZE);
	
	return 0;
}
