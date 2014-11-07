#include <bits/stdc++.h>

using namespace std;

class BIT
{
	int size;
	vector<int> v;
	vector<int> m;
	vector<bool> inc;
	vector<bool> dec;
	public : 
	// CONSTRUCTOR
	BIT(int sz)
	{
		size = sz;
		v.resize(sz+1);
		m.resize(sz+1);
		inc.resize(sz+1);
		dec.resize(sz+1);
		for(int i=1;i<=sz+1;i++)
		m[i]=INT_MIN;
	}
	// insert
	void insert(int i,int val)
	{
		int j=i;
		while(i <= size)
		{
			v[i] += val;
			i += (i&(-i));
		}
		i = j;
		while(i <=size)
		{
			m[i] = max(m[i],val);
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
	// max_element_in_range
	long long max_element_in_range(int i,int j)
	{
		long long m1 = max_element(i);
		long long m2 = max_element(j);
		return max(m1,m2);
	}
	// max_element
	long long max_element(int i)
	{
		int s = INT_MIN;
		while(i>0)
		{
			s = max(m[i],s);
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

	// range_sum
	long long range_sum(int i,int j)
	{
		long long sum_i = prefix_sum(i-1);
		long long sum_j = prefix_sum(j);
		return sum_j - sum_i;
	}
	// is_incresing
	bool is_inc()
	{
		
	}
	void display()
	{
		for(int i=1;i<=size;i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
};

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	BIT bit(n);
	int x,a[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=x;
		bit.insert(i,x);
	}
	
	char c;
	int y;
	while(m--)
	{
		cin>>c>>x>>y;
		if(c=='S')
		{
			cout<<bit.range_sum(x,y)<<endl;
		}
		else if(c=='U')
		{
			bit.update_range(x,x,y);
		}
		else if(c=='M')
		{
			cout<<bit.max_element_in_range(x,y)<<endl;
		}
		else if(c=='I' || c== 'D')
		{
			
		}
	}
	return 0;
}

