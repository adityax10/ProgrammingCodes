#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	int n =50;
	
	for(int i=1;i<=n/2;i++)
	{
		for(int j=0;j<n/2 - i;j++)
		cout<<" ";
		cout<<".";
		for(int k=0;k<=2*sqrt(2*n*i - i*i);k++)
		cout<<"-";
		cout<<"~";
		cout<<endl;
	}
	for(int i=n/2;i<n;i++)
	{
		for(int k=0;k<=(i-n/2);k++)
		cout<<" ";
		cout<<".";
		int j = n-i;
		for(int k=1;k<=2*sqrt(2*n*j - j*j);k++)
		cout<<"-";
		cout<<"~";
		cout<<endl;
	}
	
	/*for(int i=0;i<n/5;i++)
	{
		for(int j=0;j<n/2-i;j++)
		cout<<" ";
		cout<<".";
		for(int k=0;k<=2*i + 1;k++)
		cout<<"|";
		cout<<".";
		cout<<endl;
	}*/
	
	return 0;
}

