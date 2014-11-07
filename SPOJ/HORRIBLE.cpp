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
	cin>>cases;
	while(cases--)
	{
		int n,c;
		cin>>n>>c;
		BIT bt(100000);
		while(c--)
		{
			int t,i,j,val; 
			cin>>t>>i>>j;
			if(t==0)
			{
				cin>>val;
				bt.update_range(i,j,val);
			}
			else 
			{
				cout<<bt.range_sum(i,j)<<endl;
			}
		}
	}
	return 0;
}

