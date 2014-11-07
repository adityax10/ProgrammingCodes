#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

long long a[100005];

long long max_area_in_histogram(long long n)
{
	vector<long long> s;
	long long max_area=0,area;
	long long i=0;
	while(i<n)
	{
		if(s.empty() || a[i] > a[s.back()])
		s.push_back(i++);
		else
		{
			long long x = s.back();
			s.pop_back();
			area = s.empty()? (a[x]*i ):(a[x]*(i-s.back()-1));
			max_area=max(area,max_area);
		}
		//cout<<"Area : "<<area<<"Max_Area "<<max_area<<endl;
		//for(long long i=0;i<s.size();i++)
		//cout<<a[s[i]]<<" ";
		//cout<<endl;
	}
	while(!s.empty())
	{
			long long x = s.back();
			s.pop_back();
			area = s.empty()?a[x]*i :a[x]*(i-s.back()-1);
			max_area=max(area,max_area);
	}
	return max_area;
}

int main()
{
	long long n,_n,i=0;
	cin>>n;
	while(n!=0)
	{
	i=0;
	_n=n;
	while(_n--)
	{
		cin>>a[i++];
	}
	cout<<max_area_in_histogram(n)<<endl;
	cin>>n;
    }
	return 0;
}


