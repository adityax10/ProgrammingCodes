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
bool visit_in_progress[10000];
int elec_nos=0;
vector<int> ans;
vector< pair<city,city> > to_be_repaired;

void repair()
{
	cout<<"REpairing \n";
	while(!to_be_repaired.empty())
	{
		cout<<"Size of : "<<to_be_repaired.size()<<endl;
		pair<city ,city> p = to_be_repaired.back();
		cout<<"Road b/w Cities "<<p.first.nam<<" "<<p.second.nam<<endl;
		int i=0;
		while(p.first.link[i].second->nam!=p.second.nam)
		i++;
		p.first.link[i].first = 1;
		i=0;
		while(p.second.link[i].second->nam!=p.first.nam)
		i++;
		p.second.link[i].first = 1;
		to_be_repaired.pop_back();
		cout<<"Popped !\n";
	}
	cout<<"end\n";
}


int calculate(city *cx,int i)
{
	cout<<"IN Calculate with vertex : "<<cx->nam<<endl;
	if(visit_in_progress[cx->nam]==0)
	{
	//char c;
	//cin>>c;
	cout<<"Checking Vertex : "<< cx->nam <<" T.S "<<cx->link.size()<<" for link Number : "<<i<<endl;
	visit_in_progress[cx->nam]=1;
	while(i < cx->link.size())
	{ 
	    cout<<"Exploring Ajs of : "<< cx->nam<<endl; 
		if(cx->link[i].first == 0)
		{
		pair<city,city> p;
		p.first = *cx;
		p.second = *cx->link[i].second;
		to_be_repaired.push_back(p);
	    }
	    while(visit_in_progress[cx->link[i].second->nam] == 1 )
	    {
	    i++;
	    if(i>=cx->link.size())
	    return 0;
	    }
	    
		calculate(cx->link[i].second,0);
		if(cx->link[i].first == 0)
		{
			elec_nos++;
			ans.push_back(cx->link[i].second->nam);
			repair();
		}
		i++;
	}
    }
    cout<<"REtunrning \n";
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
	    
		
		l.second= &c[c_n];
	//	c[c_n].p = &c[c_l];
	//	c[c_l].nam = c_l;
	//	c[c_n].nam = c_n;
		c[c_l].link.push_back(l);
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


