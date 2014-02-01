#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int lli;

lli mulmod(lli a,lli b,lli c){
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

int main()
{
    lli x = mulmod(1000000000,1000000000,10000);
	cout<<x;
	return 0;
}


