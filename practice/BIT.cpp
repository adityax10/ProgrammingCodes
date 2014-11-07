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
	// range_sum
	long long range_sum(int i,int j)
	{
		long long sum_i = prefix_sum(i-1);
		long long sum_j = prefix_sum(j);
		return sum_j - sum_i;
	}
	void display()
	{
		for(int i=1;i<=size;i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
};

int main(int argc, char** argv) {
	
	return 0;
}

