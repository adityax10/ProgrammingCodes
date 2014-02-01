#include<iostream>
using namespace std;

int max(int &x,int &y)
{
	return x>y?x:y;
}


int rodcut(int n)
{
	if(n==1)
	return  1;
	
	return max((n/2)*(n-n/2),rodcut(n/2)*rodcut(n-n/2));
}

int main()
{
	cout<<rodcut(100);
}
