#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

double d[100000];

int main()
{
	int t;
	cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		int i=0;
		while(i--)
		{
			int k=n;
			while(k--)
			cin>>d[i];
			sort(d+0,d+n-1);
			double x;
			int j=1;
			while(m--)
			{
				cout<<"Case :"<<j<<endl;
				j++;
				cin>>x;
				//int count=0;
				int l=1;
				int z=n-1;
				while(x)
				{
					cout<<"Scenario :"<<l<<endl;
					l++;
					if(x/d[z]>=0)
					{
						
						x=fmod(x,d[z]);
						cout<<d[z]<<" "<<x/d[z];
					}
					else
					{
						z--;
					}
				}
			}
			
		}
		
	}

	return 0;
}


