#include <bits/stdc++.h>

using namespace std;

bool a[100003];

int main(int argc, char** argv) {
	int n,d;
	cin>>n>>d;
	int i = 1;
	int j=d;
	vector<int> v;
	cout<<"1 ";
	a[1]=1;
	int count =1;
	v.push_back(i);
	while(count!=n)
	{
		i = v.back();
		if(j<=0)
		j=d;
		for(;j>=1;j--)
		{
			if(i+j <= n && !a[i+j])
			{
				cout<<i+j<<" ";
				count++;
				a[i+j]=1;
				v.push_back(i+j);
				break;
			}
			else if(abs(i-j) <= n&& i!=j  && !a[abs(i-j) ])
			{
				cout<<abs(i-j) <<" ";
				a[abs(i-j) ]=1;
				count++;
				v.push_back(abs(i-j) );
				break;
			}
		}
	}
	
	return 0;
}

