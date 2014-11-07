#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<unsigned long long ,unsigned long long > ans;

unsigned long long compute_pow(int x,unsigned long long n)
{
	if(n==1)
	return x;
	else if(n==0)
	return 1;
	else if(ans[n]!=0)
	return ans[n];
	ans[n] = (compute_pow(x,n/2)*compute_pow(x,n-n/2))%1000000007; 
	return ans[n];
}

int binary_search(const vector<int> v,int x)
{
	int l=0;
	int r=v.size()-1;
	while(r>=l)
	{
		int mid = (l+r)/2;
		
		if(v[mid]==x)
		return mid;
		else if(v[mid] > x)
		r=mid-1;
		else
		l=mid+1;
	}
	return -1;
}

unsigned long long cal(vector<int> v,int x,int y)
{
	int pos_x = binary_search(v,x);
	int pos_y = v.size();
	int n = pos_y-pos_x;
	
	if(n-2>=0)
	return compute_pow(2,n-2)+1;
	else
	return 1;
}

int main()
{
	int n,b,q;
	vector <int> v;
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cin>>q;
	sort(v.begin(),v.end());
	while(q--)
	{
		int y;
		cin>>y;
		cout<<cal(v,y,b)<<endl;
	}
	return 0;
}

