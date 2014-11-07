#include<iostream>

using namespace std;

int main()
{
	unsigned long n;
	unsigned long long ans;
	int cases;
	
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		ans=1;
		for(int i=0;i<n;i++)
		{
			ans=(ans*2)%1000000009;
		}
		ans--;
		cout<<ans<<"\n";
	}
	return 0;
}
