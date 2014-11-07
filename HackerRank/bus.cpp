#include <bits/stdc++.h>

using namespace std;

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
		total_sum += sum;
		v.push_back(x);
	}
	n = v.size();
	
	int i =0;
	long long sum = 0;
	while(i<n)
	{
		sum += v[i];
	//	cout<<"Sum "<<sum<<endl;
		long long curr_sum =0;
		int j =i+1;
		bool broke = 0;
		while(j<n)
		{
			if(curr_sum+v[j]<sum)
			{
			curr_sum+=v[j];
			j++;
			}
			else if(curr_sum+v[j]==sum)
			{
				curr_sum = 0;
				j++;
			}
			else
			{
				broke=1;
				break;
			}
		}
		if(curr_sum==0 && !broke)
		cout<<sum<<" ";
		i++;
	}
	
	return 0;
}

