#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"Sem ?"<<endl;
	int s;
	cin>>s;
	double cul = 0;
	double total_c=0;
	while(s--)
	{
		cout<<"Credits ?";
		double c;
		cin>>c;
		cout<<"Pointer ?";
		double p;
		cin>>p;
		cul+=p*c;
		total_c+=c;
	}
	cout<<"CGPA : "<<cul / total_c<<endl;
	return 0;
}


