#include <bits/stdc++.h>

using namespace std;

#define lli long long int
lli MOD = 1000000007;
inline lli mulmod(lli a,lli b,lli c){
	lli x = 0,y=a%c;
	while(b > 0){
	if(b%2 == 1){
	x = (x+y)%c;
	}
	y = (y*2)%c;
	b /= 2;
	}
	return x%c;
}

lli power(int x, int n)
{
	if(n==0)
	return 1;
	if(n==1)
	return x;
	
	lli temp = power(x,n/2);
	temp = mulmod(temp,temp,MOD);
	if(n%2)
	return mulmod(temp,x,MOD);
	else
	return temp;	
} 

int main(int argc, char** argv) {
	lli n;
	cin>>n;
	if(n<=12)
	cout<<0<<endl;
	else
	{
	n=(n-1)/2;
	lli num=1;
	lli denm=1;                                                       
	// num
	for(int j=1;j<=6;j++)
	{
	 	num = mulmod(num,n,MOD);
	 	denm *= j;
	 	n--;
	}
	// denum
	denm = power(denm,MOD-2);
	cout<<mulmod(num,denm,MOD)<<endl;
	}
	return 0;
}

