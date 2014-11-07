#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

typedef unsigned long long int ulli; 

ulli cal_power(ulli a,ulli b,ulli c) // computes pow with log(b)
{
	ulli x = 1; ulli y = a%c;
	while(b)
	{
		if(b%2 == 1)
		{
			x = (x*y)%c;
		}
		 y = (y*y)%c;
		 b =  b/2;
	}
	return x%c;
}

// cal_power(a,p-1,p) = 1)
// if for anyvalue of a if LHS !=1 then,p isn't prime !
/* Fermat's test for checking primality, the more iterations the more is accuracy */
bool check_prime(long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1; 
        // modulo is the function we developed above for modular exponentiation.
        if(cal_power(a,p-1,p) != 1){ 
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}

int main()
{
	
	int cases,m,n;
	cin>>cases;
	while(cases--)
	{
		cin>>m>>n;
		for(int i=m;i<=n;i++)
		{
			if(check_prime(i,20))
			cout<<i<<endl;
		}
		cout<<"\n";
	}
	
	return 0;
}


