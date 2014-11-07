#include <iostream>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		while(n--)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		long long g = 0,a = 0;
		for(int i=0;i<v.size();i++)
		{
			g+=v[i];
			if(g>0)
			a+=g;
			else
			a+=-g;
		}
		cout<<a<<endl;
		v.clear();
	}
	return 0;
}

