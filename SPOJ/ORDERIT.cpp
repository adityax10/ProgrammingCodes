#include <bits/stdc++.h>

using namespace std;

class BIT
{
	int size;
	vector<int> v;
	public : 
	// CONSTRUCTOR
	BIT(int sz)
	{
		size = sz;
		v.resize(sz+1);
	}
	// insert
	void insert(int i,int val)
	{
		while(i <= size)
		{
			v[i] += val;
			i += (i&(-i));
		}
	}
	// prefix_sum
	long long prefix_sum(int i)
	{
		long long s = 0;
		while(i>0)
		{
			s += v[i];
			i -= (i&(-i));
		}
		return s;
	}
	// update range
	void update_range(int i,int j,int val)
	{
		insert(i,val);
		insert(j+1,-val);
	}	
	void display()
	{
		for(int i=1;i<=size;i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
};

int main(int argc, char** argv) {
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		BIT bt(n);
		while(m--)
		{
			int l,r,val;
			scanf("%d %d %d",&l,&r,&val);
			bt.update_range(l+1,r+1,val);
			bt.display();
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			printf("%lld \n",bt.prefix_sum(x+1));
		}
	}
	return 0;
}

