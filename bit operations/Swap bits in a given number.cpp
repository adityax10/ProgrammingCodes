#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	int num = 28;
	int p1=0;
	int p2 = 3;
	int n = 2; //shifts
	
	int ones = (1<<n) - 1;
	
	int m1=ones,m2=ones; //masks
	
	m1=m1<<p1;
	m2=m2<<p2;
	
	int num1 = (num&m1)<<(p2-p1);
	int num2 = (num&m2)>>(p2-p1);
	
	int mf = ~(m1+m2); //master mask
	int num3 = num&mf;
	
	cout<<num1+num2+num3;
	
	
	return 0;
}


