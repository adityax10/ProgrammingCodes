#include<iostream>
using namespace std;

int main()
{
	int x,y;
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>x>>y;
		unsigned long long int n = y-x +1;
		cout<< n*(n-1)/2<<endl;
	}
	return 0;
}


