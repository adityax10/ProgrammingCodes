#include<iostream>
using namespace std;
int main()
{
	double x=0,temp=0;
	while(1)
	{
		int k=8;
		while(k--)
		{
			cin>>temp;
			x+=temp;
		}
		cout<<"Total : "<<x<<" "<<(double)x/8<<endl;
		x=0;
	}
	return 0;
}


