#include <bits/stdc++.h>

using namespace std;

bool check(int sum,vector<int> &a)
{
	int curr=0;
	for(int i=0;i<a.size();i++)
	{
		if(curr+a[i]<sum)
		curr+=sum;
		else if(curr+a[i]==sum)
		{
		curr=0;
		continue;
		}
		else
		return false;
	}
	if(curr==0)
	return true;
	else
	return false;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int total_sum =0;
	vector<int> v;
	while(n--)
	{
		int x;
		cin>>x;
		total_sum += x;
		v.push_back(x);
	}
	n = v.size();
	vector<int> ans;
	for(int i=1;i*i<=total_sum;i++)
	{
		if(!(total_sum%i) && check(i,v))
		{
			ans.push_back(i);
			if(check(total_sum/i,v))
			ans.push_back(total_sum/i);
		}
	}
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
	
	return 0;
}

