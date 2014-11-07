#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int a[1000002];

int main()
{
	int n,q,ans;
	char m;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    while(q--)
    {
    	int i,j;
    	cin>>m;
    	cin>>i>>j;
    	if(m=='S')
    	{
    		ans=0;
    		for(int z=i;z<=j;z++)
    		ans+=a[z];
    		cout<<ans<<endl;
    	}
    	else if(m=='G')
    	{
    		a[i]+=j;
    	}
    	else
    	 a[i]-=j;
    }

	return 0;
}



