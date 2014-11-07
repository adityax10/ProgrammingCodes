#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	map<int,int> memo;
	for (int i=0;i<n;i++) {
		int temp = arr[i];
		for (int j=i;j<n;j++) {
			temp = min(temp,arr[j]);
			memo[temp]++;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		cout << memo[k] << endl;
	}
	return 0;
}


