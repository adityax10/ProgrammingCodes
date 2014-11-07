#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void get_Stock_Span(int *a,int n)
{
	vector<int> v;
	int s[n];
	for(int i =0;i<n;i++)
	{
		if(v.empty() || (a[i] < a[v.back()]))
		{
			v.push_back(i);
		}
		
		if(a[i] >= a[v.back()] )
		{
			while( !v.empty() && a[i] >= a[v.back()]) // = !!
			{
				v.pop_back();	
			}
			s[i]=(v.empty()?i+1:i-v.back());
			v.push_back(i);
			continue;
	    }
	    
		s[i]= (v.empty()?i+1:i-v.back()+1);
	}
	for(int i=0;i<n;i++)
	cout<<s[i]<<" ";
}

int main()
{
	int stock_prices[]={6,2,5,4,5,1,6};
	int n = sizeof(stock_prices)/sizeof(stock_prices[0]);
	get_Stock_Span(stock_prices,n);

	return 0;
}


