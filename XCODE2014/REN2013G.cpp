#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<utility>
using namespace std;

long x[10001][2];
long dist[1001][1001];
long cost[1001];
bool visited[1001];

long magnitue(long a[2],long b[2])
{
	return (b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]);
}

class compareClass{
	public:
		bool operator() (pair<long,long> &x,pair<long,long> &y)
		{
			//cout<<"Comparing : "<<x.second<<" "<<y.second<<endl;
			if((x.second) > (y.second))  return true; // for min priority Heap
			//if (y > x) return true; //for max Heap
			else
			return false;
		}
};

long cal_min_distance_am(long dist[][1001],long n)
{
	for(long i=1;i<n;i++)
	{
	cost[i]=INT_MAX;
	}
	cost[0]=0;
	priority_queue< pair<long,long>,vector<pair<long,long> >,compareClass> q;
	
	q.push(make_pair(0,cost[0]));
	
	while(!q.empty())
	{
		pair<long,long> pt = q.top();
		q.pop();
		long s = pt.first;
		if(!visited[s])
		{
		visited[s]=1;
		cout<<"Min Dis :"<<pt.second;
		cout<<" From "<<s<<endl;
		for(long i=0;i<n;i++)
		{
			if(cost[i] > cost[s]+dist[s][i])
			{
			cost[i]=cost[s]+dist[s][i];
	    	cout<<"cost["<<i<<"] : "<<cost[i]<<endl;
			q.push(make_pair(i,cost[i]));
	      	}	
		}
	    }    
	}
	return cost[n-1];
}

int main()
{
	long towers,i=1;
	cin>>towers;
	long n = towers+2;
	x[0][0]=0; // Kingdom
	x[0][1]=0;
	while(towers--)
	{
		cin>>x[i][0]>>x[i][1];
		i++;
	}
	cin>>x[i][0]>>x[i][1]; // Village
	
	for(long i=0;i<n;i++)
	{
		for(long j=0;j<n;j++)
		{
			if(i==j)
			{
			//cout<<"0 ";
			continue;
		    }
			if(dist[j][i])
			dist[i][j]=dist[j][i];
			else
			dist[i][j]= magnitue(x[i],x[j]);
			//cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<cal_min_distance_am(dist,n)<<endl;
	return 0;
}


