#include<iostream>

using namespace std;

int main()
{
	unsigned long n;
	int cases;
	
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		cout<<((unsigned long long)((1<<n)-1))%1000000009<<"\n";
	}
	return 0;
}
