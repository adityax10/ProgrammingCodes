#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

typedef struct city
{
	int nam;
	vector< pair<bool,struct city* > >link; //children
	struct city *p; //parent
}city;

city c[100000];

void repair(city *cx)
{
	//cout<<"Repairing for "<<cx->nam<<endl;
	while(cx != &c[1])
	{
		int x=0;
		while(cx->p->link[x].second != cx)
		x++;
	    cx->p->link[x].first = 1;	
		//cout<<"Repaired Link to : "<<cx->p->link[x].second->nam<<endl;
		cx = cx->p;
	}
}
int elec_nos=0;
vector<int> ans;
int calculate(city *cx,int i)
{
	//cout<<"Checking Vertex : "<< cx->nam <<" T.S "<<cx->link.size()<<" for link Number : "<<i<<endl;
	while(i < cx->link.size())
	{
		calculate(cx->link[i].second,0);
		if(cx->link[i].first == 0)
		{
			elec_nos++;
			ans.push_back(cx->link[i].second->nam);
			repair(cx->link[i].second);
		}
		i++;
	}
}

int main()
{
	int n;
	cin>>n;
	int i = n;
	//c[0].p = NULL;
	while((i--)-1)
	{
		int c_n,c_l,r_s;
		cin>>c_n>>c_l>>r_s;
		pair<bool,city *> l;
		 // road OK
		if(r_s == 2)
		r_s=0; // needs repairing
		l.first=r_s;
		
	    l.second= &c[c_l];
		c[c_l].p = &c[c_n];
		c[c_l].nam = c_l;
		c[c_n].nam = c_n;
		c[c_n].link.push_back(l);
	}
	
	
	
	i=n;
	calculate(&c[1],0);
	cout<<elec_nos<<endl;
	while(elec_nos--)
	{
		cout<<ans[elec_nos]<<" ";
	}
	cout<<endl;
	return 0;
}


