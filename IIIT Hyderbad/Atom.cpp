#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ulli;

ulli cal_ans(ulli b,ulli a)
{
	ulli ans = 0;
	while(a)
	{
		a = a/b;
		ans++;
	}
	if(ans)
	return ans-1;
	else 
	return 0;
}

int main()
{
	ulli n,k,m;
	int cases;
	cin>>cases;
	while(cases--)
	{
	cin>>n>>k>>m;
	cout<<cal_ans(k,m/n)<<endl;
    }
	return 0;
}


