#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > coords;
map<pair<int,int> ,int> a;
bool X[1002];
bool Y[1002];
int main()
{
	int p[2]={1,-1};
	int q[2]={2,-2};	
	int cases;
	ios_base::sync_with_stdio(false);
	cin>>cases;
	while(cases--)
	{
		int n,k;
		cin>>n>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			coords.push_back(make_pair(x,y));
			X[x]=1;
			Y[y]=1;
			//cout<<"set "<<x<<""<<y<<endl;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					if(x+p[i]>=1 && x+p[i]<=n && y+q[j]>=1 && y+q[j]<=n)
					{
					//	cout<<"inserting 1 :"<<x+p[i]<< " "<<y+q[j]<<endl;
						a[make_pair(x+p[i],y+q[j])]++;
					}
					 if(x+q[j]>=1 && x+q[j]<=n && y+p[i]>=1 && y+p[i]<=n)
					{
					//	cout<<"inserting 2 :"<<x+q[j]<< " "<<y+p[i]<<endl;
						a[make_pair(x+q[j],y+p[i])]++;
					}
				}
			}
		}
		int pos=0;
		for(auto i=a.begin();i!=a.end();i++)
		{
			if(i->second>=2)
			{
				pair<int,int >  p  = i->first;
				int x = p.first;
				int y = p.second;
				//cout<<"X "<<X[x]<<" Y "<<Y[y]<<endl;
				if(X[x] || Y[y])
				continue;
				//cout<<x<<" : "<<y<<endl;
				bool flag = 0;
				for(int i=0;i<coords.size();i++)
				{
					pair<int,int> q = coords[i];
					if(abs(x - q.first) == abs(y - q.second))
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				continue;
				pos++;
			}
		}
		cout<<pos<<endl;
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		coords.clear();
		a.clear();
	}
	return 0;
}


