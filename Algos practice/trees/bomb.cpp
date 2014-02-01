#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000000000
vector<bool> prime(MAX);

void sieve () {
    for(int j=3;j<=100000;j++) {
        if(!prime[j]) {
            for(int i=2*j;i<=MAX;i+=j)
            prime[i] = true;
        }
    }
    //int k=0;
    //prime[k++] = 2;
   // for(int i=3;i<MAX;i+=2)
    //if(!arr[i])
    //prime[k++] = i;

	cout << "hi";
    for(int i=0;i<30;i++)
    cout << i << " " << prime[i] << endl;
}

int main() {
	
	sieve();
}
