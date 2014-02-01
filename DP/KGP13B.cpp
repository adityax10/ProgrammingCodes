#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	int m,k;
	vector< pair<int,int> > sd;
	int x[100];
	int cases;
	cin>>cases;
	int cas=1;
	while(cases--)
	{
		cin>>k>>m;
		int j=k;
		while(j--)
		{
		int x,y;
		cin>>x>>y;
		sd.push_back(make_pair(x,y));
	    }
	    sort(sd.begin(),sd.end());
	    j=m;
	    for(int i=0;i<=k;i++)
	    {
	    x[i]=0;
	    }
	    while(m--)
	    {
	    	int z;
	    	cin>>z;
	    	while(z--)
	    	{
	    		int xi,di;
	    		cin>>xi>>di;
	    		x[xi-1]+=di;
	    	    //0cout<<"demand "<<xi<<" "<<x[xi-1]<<endl;
	    	}
	    }
	    int rooms=0;
	    rooms = x[0];
	    for(int i=1;i<sd.size();i++)
	    {
	    	pair<int,int> pl = sd[i];
	    	int j;
	    	for(j=i-1;j >= 0;j--)
	    	{
	    		pair<int,int> pf = sd[j];
	    		int cd = x[i];
	    		//cout<<"Cmp : "<<pl.first<<" "<<pl.second<<" to "<<pf.first<<" "<<pf.second<<endl;
	    		if( x[j]!=0 && (pl.first > pf.second))
	    		{
	    			//cout<<"Got !\n";
	    			if(x[j] >= x[i])
	    			{
	    				x[j]-=x[i];
	    				break;
	    			}
					else
	    			{
	    				x[i]-=x[j];
	    				x[j]=0;
	    			}
	    		}
	    	}
	    	//cout<<"j : "<<j<<endl;
	    	if(j<0)
	    	{
	    		//cout<<"Adding roms"<<endl;
	    		rooms+=x[i];
	    	}
	    	//cout<<"Rooms : "<<rooms<<endl;
	    }
	    cout<<"Case "<<cas<<": "<<rooms<<endl;
	    sd.clear();
	    cas++;
    }


	return 0;
}


