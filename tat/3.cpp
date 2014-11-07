#include <bits/stdc++.h>
using namespace std;

#define MAX 100007

int main() 
{
    int t ;
    cin >> t ;
    while(t--) 
	{
    	bool div = true ;
        long long a,b,c,d ;
        vector<long long> arr1(MAX);
		vector<long long> arr2(MAX) ;
        cin >> a >> b >> c >> d ;
        for(int i=2;i<MAX;i++ ) {
            while(a % i == 0) 
                a /= i, arr1[i] ++ ;
            while(c % i == 0) 
                c /= i , arr2[i] ++ ;
            arr1[i] *= b ;
            arr2[i] *= d ;
        }
        
        for(int i=2;i<MAX;i++) {
            if(arr2[i] > arr1[i]) {
                div = false ;
                break;
            }
        }
        
        if( c != 1 && a != c)
            div = false ;
       
        if(div == true)
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
    return 0;
}
