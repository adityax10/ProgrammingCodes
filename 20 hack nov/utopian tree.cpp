#include<iostream>

using namespace std;

int main()
{
	int cases,n;
	
	cin>>cases;
	
	while(cases--)
	{
		cin>>n;
		cout<<((unsigned long long )(1<<(n/2 +1+ n%2)))-1-(n%2)<<endl;
	}
	return 0;
}
