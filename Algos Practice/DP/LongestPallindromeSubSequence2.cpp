#include<iostream>
#define SIZE 11

using namespace std;

int l[SIZE][SIZE];

int lps(int a[],int i,int j)
{
	if(i==j)
	return 1;
	
	if(l[i][j]!=0)
	return l[i][j];
	
	if(a[i]==a[j])
	l[i][j] = lps(a,i+1,j-1)+2;
	else
	l[i][j] = max(lps(a,i,j-1),lps(a,i+1,j));
	return l[i][j];
}

int main()
{
	int a[SIZE]={1,2,3,4,2,1,2,4,5,2,1};
	
	cout<<lps(a,0,SIZE)<<endl;
	
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		cout<<l[i][j]<<" ";
		cout<<endl;
	}
}
