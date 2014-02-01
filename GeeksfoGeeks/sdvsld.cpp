#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	int h1,m1,h2,m2;
	int cases;
	double dist;
	cin>>cases;
	cout<<std :: fixed;
	while(cases--)
	{
		char x;
		cin>>h1>>x>>m1;
		cin>>h2>>x>>m2;
		cin>>dist;
		
		double m = (double)(h1-h2)*60 + m1-m2;
		cout<<std :: setprecision(1)<<m+dist * 1.0;
		
		if(2*dist <= m)
		cout<<" "<<std :: setprecision(1)<<m * 1.0 <<endl;
		else
		{
			cout<<" "<<std :: setprecision(1)<<dist + ((m)/2 ) <<endl;
		}
		
	}

	return 0;
}


