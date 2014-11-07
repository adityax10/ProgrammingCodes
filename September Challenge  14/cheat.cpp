#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>,int> ans;

int ways(int spaces,int ind,int i)
{
	if(i>7)
	return 0;
	
	if(ans[make_pair(ind,i)]!=0)
	return ans[make_pair(ind,i)];
	
	if(spaces==0)
	{
		return 1;
	}
	else
	{
		int x=0,y=0;
		y = ways(spaces-1,ind+1,i);
		ans[make_pair(ind+1,i)]= (y)%1000000007;
		if(i+1<8)
		{
		x = ways(spaces,ind+1,i+1);
		ans[make_pair(ind+1,i+1)]= (x)%1000000007;
		}
		return (x+y)%1000000007;
	}
}

int main(int argc, char** argv) {
	freopen("o.txt","w",stdout);
	//for(int i=2;i<100;i++)
	{
	cout<<ways(10000,0,1)<<endl;
	//ans.clear();
	}
	return 0;
}

