#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
// O(n) preprocessing
void RMQ(int a[],int min_store[],int n)
{
	for(int i =0;i<n;i++)
	min_store[i]=i;
	
	int sr = sqrt(n);
	for(int j=0;j<sr;j++)
	{
		int mn = j*sr;
		cout<<"ini mn "<<a[mn]<<endl;
		for(int i=(j*sr)+1 ; i<(j+1)*sr ; i++)
		{
			mn = (a[mn]>a[i])?i:mn;
			cout<<"mn in loop "<<a[mn]<<endl;
		}
		min_store[j*sr]=mn;
		cout<<"Final :"<<a[min_store[j*sr]]<<endl;
	}
	if(sr*sr!=n)
	{
		min_store[sr*sr]=sr*sr ;
		for(int i=sr*sr +1;i<n;i++)
		{
			min_store[sr*sr]= (a[i]<a[min_store[sr*sr]])?i:min_store[sr*sr];
		}
		cout<<a[min_store[sr*sr]];
    }
	return;
}

int retrieve(int a[],int min_store[],int s,int e)
{
	int sr=sqrt(n);
	for(int i = s;s<=e;i++)
	{
		
	}
}


int main()
{
	int a[]  = {7,1,2,3,41,8,34,67};
	int n = sizeof(a)/sizeof(int);
	int min_store[(int)sqrt(n)+5];
	RMQ(a,min_store,n);
	
	
	
	return 0;
}


