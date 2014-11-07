#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int k,c,d,n,m;
	//freopen("in.txt","r",stdin);
	cin>>c>>d;
	cin>>n>>m;
	cin>>k;
	
	int x = 0;
	x+=k;
	bool flag =0;
	int probs = 0;
	while(x<n*m)
	{
		if(flag==0)
		{
		flag=1;
		x+=n;
		probs+=c;
		}
		
		if ( d*n > c &&  (d*(n*m - x) >= c) && x<n*m )
		{
			x+=n;
			probs+=c;
		}
		else if(x<n*m)
		{
			x+=1;
			probs+=d;
		}
	}
	cout<<probs<<endl;
	
	return 0;
}


