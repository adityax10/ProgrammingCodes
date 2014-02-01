#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	
	int l,r,a[1001][2];
	int cases;
	string ans;
	cin>>cases;
	while(cases--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1];
		}
		int count=0;
		for(int i=0;i<n-1;i++)
		{
			while(a[i][1]>a[i+1][1])
			{
			//	cout<<"3";
			count++;
			ans.append("R-");
			a[i][1]--;
		    }
			while(a[i][1]<a[i+1][1])
			{
			///	cout<<"4";
			count++;
			ans.append("R+");;
			a[i][1]++;
		    }
		    
			//cout<<"Converting";
			while(a[i][0]>a[i+1][0])
			{
			//cout<<"1";
			count++;
			ans.append("L-");
			a[i][0]--;
		    }
			while(a[i][0]<a[i+1][0])
			{
			//	cout<<"2";
			count++;
			ans.append("L+");
			a[i][0]++;
		    }
		    
		    
		   // sort(ans.begin(),ans.end());
		    //cout<<ans<<endl;
		}
		cout<<count<<endl;
		cout<<ans<<endl;
		ans.clear();
		count=0;
		
	}


	return 0;
}


