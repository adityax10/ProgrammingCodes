#include<iostream>
#include<string>

using namespace std;


int LCA(string a,string b,int i,int j,string &ans,int k)
{

	if(i<0 || j<0)
	{
		return 0;
	}
		if(a[i]==b[j])
		{
		ans[k++]=a[i];
		return 1 + LCA(a,b,i-1,j-1,ans,k);
	    }
		else
		{
			return max (LCA(a,b,i,j-1,ans,k),LCA(a,b,i-1,j,ans,k));
		}
}

int main()
{
	string a,b,ans;
	a="jadoo";
	b="aditya";
	
	cout<<LCA(a,b,a.length()-1,b.length()-1,ans,0);
	cout<<ans<<"\n";
}
