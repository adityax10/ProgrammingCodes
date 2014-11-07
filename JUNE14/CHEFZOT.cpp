#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,x,z_i=-1,i=0;
	cin>>n;
	int max_len=0;
	
	while(n--)
	{
		cin>>x;
		if(x==0 || z_i==-1)
		{
			if(x!=0 && z_i==-1)
			max_len = max(max_len,i+1);
			else
			{
			max_len = max(max_len,i-z_i-1);
			z_i=i;
			}
		}
		i++;
	}
	
	cout<<max_len<<endl;
	return 0;
}


