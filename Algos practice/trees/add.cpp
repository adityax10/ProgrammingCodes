#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int n,a;
	vector<long long> one(30);
	cin >> n ;
	while (n--) {
		
		cin >> a;
		for (int i = 0 ; i < 30 ; i ++) {
			
			if ( a & (1 << i))
				one[i]++;
		}
	}
	
	long long sum = 0;
	for (int i = 0 ; i < 30 ; i ++) {
		
		sum += one[i]*(one[i]-1)*(1LL << i);
	}
	cout << sum/2 << endl;
}
