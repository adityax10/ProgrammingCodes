#include <bits/stdc++.h>

using namespace std;

int power(int x, int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return x;
	int temp = power(x,n/2);
	if(n%2)
	return temp*temp*x;
	else
	return temp*temp;	
} 

int main(int argc, char** argv) {
	for(int i=0;i<10;i++)
	{
		cout<<power(2,i)<<endl;
	}
	return 0;
}

