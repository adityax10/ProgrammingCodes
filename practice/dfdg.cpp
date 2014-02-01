#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

vector<pair <long long int,long long int> > segs; 

long long int search(long long l,long long r,long long x)
{
	long long int mid;
	while(r>=l)
	{
		mid=(r+l)/2; 
		if(segs[mid].first<=x && segs[mid].second>=x)
		return mid;
		else if(segs[mid].first>x )
		{
			r=mid-1;
		}
		else if(segs[mid].second<x)
		l=mid+1;
	}
	return -1;
}

bool flag[3000000];

int main()
{
	unsigned long long int n,m,ans;
	long long int f,s;
	cin>>n>>m;
	for(unsigned long long int i=0;i<n;i++)
	{
		cin>>f>>s;
		pair<unsigned int,unsigned int> p;
		p.first=f;
		p.second=s;
		segs.push_back(p);
	}
	long long int k;
	
	sort(segs.begin(),segs.end());
	
	while(m--)
	{
		int e,l=0,r=n-1;
		ans=0;
		cin>>e;
		while(e--)
		{
			cin>>f;
			if((k = search(0,n-1,f))!=-1 && flag[k]!=1 )
			{
					ans++;
					//prev_seg=k;
					flag[k]=1;
			}
		}
		cout<<ans<<endl;
		for(long long int i=0;i<n;i++)
		flag[i]=0;
    }
	return 0;
}


