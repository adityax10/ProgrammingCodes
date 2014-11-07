#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > pq,nq;

int main(int argc, char** argv) {
//	freopen("in.txt","r",stdin);
	int cases;
	cin>>cases;
	while(cases--)
	{
		int x,n,i=0;
		cin>>n;
		while(i<n)
		{
			cin>>x;
			if(x>0)
			pq.push_back(make_pair(i+1,x));
			else if(x<0)
			nq.push_back(make_pair(i+1,-x));
			i++;
		}
		long long moves = 0;
		while(!pq.empty() && !nq.empty())
		{
			pair<int,int> pos = pq.back();
			pair<int,int> neg = nq.back();
			//cout<<"Pos : "<<pos.first<<" "<<pos.second<<endl;
			//cout<<"Neg : "<<neg.first<<" "<<neg.second<<endl<<endl;
			if(pos.second > neg.second)
			{
				pq.pop_back();
				nq.pop_back();
				moves += abs(pos.first - neg.first) * (neg.second);
				pq.push_back(make_pair(pos.first,pos.second-neg.second));
			}
			else if(pos.second < neg.second)
			{
				pq.pop_back();
				nq.pop_back();
				moves += abs(pos.first - neg.first) * pos.second;
				nq.push_back(make_pair(neg.first,-pos.second+neg.second));
			}
			else
			{
				pq.pop_back();
				nq.pop_back();
				moves += abs(pos.first - neg.first) * pos.second;
			}
		}
		cout<<moves<<endl;
	}
	return 0;
}

