#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a=b;
	b= temp;
}

void sort(int a[],int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		min = i;
		for(int j=i;j<n;j++)
		{
			if(a[min]>a[j])
			min =j;
		}
		swap(a[min],a[i]);
	}
}

int main()
{
	int a[]= {4,3,6,2,6,2,8,3};
	sort(a,8);
	for(int i=0;i<8;i++)
	cout<<a[i]<<" ";
	
	return 0;
}


