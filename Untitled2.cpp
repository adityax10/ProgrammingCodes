#include<iostream>

using namespace std;

int main()
{
	int i=0;
	
	int j=0;
	
	b:
		j++;
		i++;
	if(i<256)
	goto b;
	cout<<j;
}
