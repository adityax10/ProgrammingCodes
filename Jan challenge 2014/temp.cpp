#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ulli;

ulli mulmod(ulli a,ulli b,ulli c){
    ulli x = 0,y=a%c;
    while(b > 0){
    	cout<<"x : "<<x<<"y "<<y<<"b "<<b<<endl;
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int main()
{
	cout<<mulmod(5,11,1000);
}


