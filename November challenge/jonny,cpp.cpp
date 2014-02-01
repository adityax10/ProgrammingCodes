#include<iostream>

using namespace std;

int main()
{
    unsigned long a[101];
	int n,cases,k;
	int count;
	
	cin>>cases;
	while(cases--)
	{
		count=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cin>>k;
		for(int i=0;i<n;i++)
		{
			if(a[i]<a[k-1])
			{
				count++;
			}
		}
		cout<<count<<"\n";
	}
	
	
	
	return 0;
}
