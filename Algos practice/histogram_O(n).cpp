#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int max_area_in_histogram(int *a,int n)
{
	vector<int> s;
	int max_area=0,area;
	int i=0;
	while(i<n)
	{
		if(s.empty() || a[i] > a[s.back()])
		s.push_back(i++);
		else
		{
			int x = s.back();
			s.pop_back();
			area = s.empty()? (a[x]*i ):(a[x]*(i-s.back()-1));
			max_area=max(area,max_area);
		}
		//cout<<"Area : "<<area<<"Max_Area "<<max_area<<endl;
		//for(int i=0;i<s.size();i++)
		//cout<<a[s[i]]<<" ";
		//cout<<endl;
	}
	while(!s.empty())
	{
		int x = s.back();
			s.pop_back();
			area = s.empty()?a[x]*i :a[x]*(i-s.back()-1);
			max_area=max(area,max_area);
	}
	return max_area;
}

int main()
{
	int a[] = 	{0,1,1,0,0,1};
	int n = sizeof(a)/sizeof(int);
	cout<<max_area_in_histogram(a,n);

	return 0;
}


