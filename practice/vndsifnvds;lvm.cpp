#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int l,r;
void divide(int s,int i)
{
	while(s && i)
	{
		int x =s/i;
		if(x>=l && x <=r)
		{
			cout<<x<<" ";
			s-=x;
			i--;
		}
	}
}

int main()
{
	int n,k,sa,sk;
	cin>>n>>k>>l>>r>>sa>>sk;
	int sl=sa-sk;
	int i = n-k;
	divide(sk,k);
	divide(sl,i);
	cout<<endl;
	return 0;
}


