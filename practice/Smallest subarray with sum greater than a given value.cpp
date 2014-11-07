#include <bits/stdc++.h>

using namespace std;

int min(int x,int y)
{
	if(x<y)
	return x;
	else
	return y;
}

int dp(int a[],int i,int k,int n,int s)
{
	if(i>n)
	return INT_MAX;
	
	if(s<0)
	return k;
	
	return min( dp(a,i+1,k+1,n,s-a[i]) , dp(a,i+1,k,n,s) );
}


int main(int argc, char** argv) {
	int a[]= {1,4,45,6,3};
	int s = 51;
	cout<<dp(a,0,0,sizeof(a)/sizeof(int),s);
	return 0;
}

