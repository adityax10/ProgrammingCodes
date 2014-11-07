#include<bits/stdc++.h>
using namespace std;

int cal_dp(vector<int> &s)
{
	int n = s.size();
	int m[n+1];
	
	int same[10];
	for(int i=0;i<10;i++)
	{
		same[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		m[i]=INT_MAX;
	}
	m[0]=0;

	for(int i=0;i<n;i++)
	{
		//cout<<"For "<<s[i]<<endl;
		//equal
		if(same[s[i]]==-1)
		{
			same[s[i]]=m[i];
			//cout<<"same["<<s[i]<<"] set : "<<m[i]<<endl;
		}
		else if(same[s[i]]!=-1)
		{
			//cout<<"setting from same[]\n";
			m[i]=same[s[i]]+1;
			//cout<<"same["<<s[i]<<"] used to set : "<<m[i]<<endl;
			int k=i;
			while(k>0 && k<n && abs(m[k-1]-m[k])>1 )
			{
				if(m[k]>m[k-1])
				{
					m[k]=m[k-1]+1;
					same[s[k]]=min(same[s[k]],m[k]);
				//	cout<<"Updating  "<<s[k]<<" as "<<m[k]<<endl;
					k++;
				}
				else
				{
					m[k-1]=min(m[k]+1,m[k-1]);
					same[s[k-1]]=min(same[s[k-1]],m[k-1]);
				//	cout<<"Updating  "<<s[k-1]<<" as "<<m[k-1]<<endl;
					k--;
				}
			}
		}
		//left
		if(i!=0)
		m[i-1]= min (m[i-1],m[i]+1);
		//right
		if(i!=n-1)
		m[i+1]= min (m[i+1],m[i]+1);
	}
	/*// display
	for(int i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;*/

	return m[n-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("in_digi.txt","r",stdin);
	vector<int> v;
	char x;
 	while(cin>>x)
	{
		v.push_back(x-'0');
	}
	
	cout<<cal_dp(v)<<endl;
	return 0;
}


