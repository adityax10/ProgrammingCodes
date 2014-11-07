#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	long long int a,b,c;
	cin>>a>>b;
	if((a%2 && b-a <=  2 )|| b-a<=1)
	cout<<"-1\n";
	else if(a%2)
	{
		cout<<a+1<<" "<<a+2<<" "<<a+3<<endl;
	}
	else
		cout<<a<<" "<<a+1<<" "<<a+2<<endl;
	return 0;
}

