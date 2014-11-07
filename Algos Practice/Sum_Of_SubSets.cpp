#include<iostream>
#define SIZE 5

using namespace std;
int m;
int flag[SIZE];

void sos(int a[],int k,int sum,int residual)
{
	if(sum+a[k]==m)
	{
		flag[k]=1;
		for(int i=0;i<SIZE;i++)
		{
			if(flag[i]==1)
			cout<<a[i]<<" ";
		}
		cout<<endl;
		flag[k]=0;
	}
	else if(a[k]+a[k+1]<=m)
	{
		flag[k]=1;
		sos(a,k+1,sum+a[k],residual-a[k]);
		flag[k]=0;
	}
	if(residual+sum-a[k] >= m && sum+a[k+1]<=m)
	//if(residual>= m-sum )
	{
		flag[k]=0;
		sos(a,k+1,sum,residual-a[k]);
	}
	
	
}

int main()
{
	int a[SIZE]={15,6,5,7,8};
	m=8;int total=0;
	for(int i=0;i<SIZE;i++)
	total+=a[i];
	sos(a,0,0,total);
}
