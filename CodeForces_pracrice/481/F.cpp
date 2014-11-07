#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	vector<long long > v(n),s(n),s_k(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	s[0]=v[0];
	for(int i=1;i<n;i++)
	s[i] = s[i-1]+ v[i];
	
	long long ans = 0;
	if(2*k<n)
	{
		int max_i=0;
		k--;
		// 1st
		for(int i=0;i+k<n;i++)
		{
			if(i==0)
			s_k[i] = s[k];
			else
			s_k[i] =s[i+k] - s[i-1];
			
			max_i =  s_k[max_i] > s_k[i] ? max_i : i;
		}
		ans+= s_k[max_i];
		//cout<<"ans1 "<<ans<<endl;
		//2nd
		k++;
		
		for(int i=max_i;i+k<n;i++)
		v[i] = v[i+k];
		
		n-=k;
		
	/*	for(int i=0;i<n;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;*/
		
		s_k.clear();
		s.clear();
		
		s[0]=v[0];
		for(int i=1;i<n;i++)
		s[i] = s[i-1]+ v[i];
		
		
	/*	for(int i=0;i<n;i++)
		cout<<s[i]<<" ";
		cout<<endl; */
		
		max_i=0;
		k--;
		
		for(int i=0;i+k<n;i++)
		{
			if(i==0)
			s_k[i] = s[k];
			else
			s_k[i] =s[i+k] - s[i-1];
			max_i =  s_k[max_i] > s_k[i] ? max_i : i;
		}
		ans+= s_k[max_i];
		
		cout<<ans<<endl;
	}
	else
	cout<<s[n-1]<<endl;
	
	return 0;
}

