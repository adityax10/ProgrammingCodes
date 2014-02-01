#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;

map<int,int> m;

int main()
{
	int n,p,cases;
	char sa[64000];
	char sb[64000];
	int count=0;
	
	cin>>n;
	cin>>p;
	cin>>sa;
	cin>>sb;
	
	
	bool start=1;
	int i_start=-1;
	int matched_cubes=0,max_cube_size=0; // in continuity
	int k =n*n*n;
	for(int i=0;i<k;i++)
	{
		if(sa[i]==sb[i])
		{
			//cout<<"MAtched\n";
		   if(start==1)
		   {
		   	//cout<<"Start\n";
		   	i_start=i;
		   	start=0;
		   }
		   if(i==k-1 && start==0)
		   {
		   	matched_cubes=i-i_start+1;
		   	max_cube_size = max(matched_cubes,max_cube_size);
	    	m[matched_cubes]++;
	    	start=1;
	    	//cout<<"matched_cubes = "<<matched_cubes;
		   }
	    }
	    else
	    {
	    	//cout<<"Missed !\n";
	    	if(start==0)
	    	{
	    		matched_cubes=i-i_start;
	    		max_cube_size = max( (i+n)/n -(i_start+n)/n ,max_cube_size);
	    		m[matched_cubes]++;
	    		start=1;
	    		//cout<<"matched_cubes = "<<matched_cubes;
	    	}
	    }
	}
	
	
	


	return 0;
}


