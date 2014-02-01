#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


bool c[1000000000];

void cal_fal (vector<pair<int,int> > sticks , vector<int> &fal) {
	
	sort(sticks.begin(),sticks.end(),[](pair<int,int> a, pair<int,int> b) {return a.first < b.first;} );
		
	for(auto i : sticks)
	cout << i.first << " " << i.second << endl;
		
	int ht ,x ,j ,count;
	
	fal[sticks[sticks.size()-1].first + 108] = 1;
	
	int m ;
	for (int i = sticks.size()-2 ; i >= 0 ; i --) {
		
		ht = sticks[i].second + sticks[i].first - 1 + 108;
		x = sticks[i].first ;
		m = -1;
		if (ht >= 217)			j = 216;
		else 								j = ht;	
		for ( ; j > x + 108; j --) {
			
			//if (m < fal[j] && )	
			//m = fal[j];
		}
		
		fal[x+108] = m + 1;
		cout << m + 1 << " ";
	}
	
}

int main() {
	
		int t;
		cin >> t;
		while(t--) {
			
			int n;
			cin >> n;
			int a,b;
			vector<pair<int,int> >  sticks(n);
			for(int i = 0 ; i < n ; i ++)  {
				cin >> a >> b ;
				sticks[i] = make_pair(a,b);
			}
			
			vector<int> fal (300);
			cal_fal(sticks,fal);
			
			for (int i = 0 ; i < sticks.size() ; i ++) {
				
				cout << fal[sticks[i].first+108] << " ";
			}
			cout << endl;
		}
		
}
