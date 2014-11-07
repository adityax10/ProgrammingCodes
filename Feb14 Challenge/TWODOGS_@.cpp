#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

inline int read() 
{
	int flag=1;
    int n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
              c=GETCHAR();
              if(i==0&&c=='-') parity=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
              i++;
    }
    return parity*n;
}


int cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first!=b.first)
	{
		return a.first<b.first;
	}
	else
	{
		return a.second<b.second;
	}
}

int bin_search(vector<pair<int,int> > &a,int x,int l,int r)
{
	int mid;
	while(r>=l)
	{
		mid=(r+l)/2;
		if(x>a[mid].first)
		l=mid+1;
		else if(x<a[mid].first)
		r=mid-1;
		else
		return mid;
	}
	return -1;
}

int main()
{
	int n,k;
	freopen("input.txt","r",stdin);
	cin >> n >> k;
	vector< pair<int,int> > a(n); // val,index
	int ans = INT_MAX;
	for(int i=0;i<n;i++)
	{
	cin>>a[i].first;
	a[i].second = i;
    }
	
	sort(a.begin(),a.end(),cmp);
	
	for(int x=0;x<n;x++)
	{
		int i = a[x].second;
		if(k-a[i].first<=0)
		continue;
		int y = bin_search(a,k-a[i].first,x,n-1);
		if(y!=-1)
		{
			while(a[y].first == a[y-1].first)
			y--;
			int j = a[y].second;
			
			
			
			if(i!=j)
			{
			
			cout<<"i "<<i<<" j "<<j<<endl;
			
			int t1 = max(i+1,n-j); //opposite
			int t2 = max(i+1,j+1); // both left
			int t3 = max(n-i,n-j); //both right
			ans = min(ans,t1);
			ans = min(ans,t2);
			ans = min(ans,t3);
		    }
		}
	}
	
	
	if(ans==INT_MAX)
	{
		cout<<"-1"<<endl;
	}
	else
	cout<<ans<<endl;
	return 0;
}


