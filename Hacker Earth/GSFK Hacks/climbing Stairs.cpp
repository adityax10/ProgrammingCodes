#include<iostream>
using namespace std;

int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	int s=0;
	//int days=0;
	
	int days = (n-a)/(a-b);
	
	if(a >= n)
	{
		cout<<1<<endl;
	}
	else
	{
	int x = days * (a-b);
	
	if(x+b >= n)
	cout<<days<<endl;
	else
	{
		while(1)
		{
			days++;
			x+=a;
			if(x>=n)
			break;
			x-=b;
		}
		cout<<days<<endl;
	}
	}
	
	return 0;
}


