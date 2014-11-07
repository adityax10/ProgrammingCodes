#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int n;

int temp[100][100];

int opt(int a[],int i,int j)
{
	//cout<<i<<" "<<j<<endl;
	if(i-j==1 || j-i ==1)
	return max(a[i],a[j]);
	if(j<0)
	return a[i];
	if(i>n)
	return a[j];
		
	if(temp[i][j]!=0)
	return temp[i][j];
	
	temp[i][j] = max( a[i]+min(opt(a,i+2,j),opt(a,i+1,j-1)) , a[j]+min(opt(a,i,j-2),opt(a,i+1,j-1)) );
	return temp[i][j];
}

int main()
{
	int a[]={20, 30, 2, 2, 2, 10};
	 n = sizeof(a)/sizeof(a[0]);
	cout<<opt(a,0,n-1);
	return 0;
}


