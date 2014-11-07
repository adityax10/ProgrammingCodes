#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int  M[MAX];

void create_binary_tree(int node,int start,int end,int a[])
{
	if(start ==  end)
	{
		M[node]=start;
	}
	else
	{
		create_binary_tree(2*node + 1,start,(end+start)/2,a);
		create_binary_tree(2*node + 2,(end+start)/2 +1,end,a);
		// now choose the parent node
		if(a[M[2*node + 1]] < a[M[2*node + 2]])
		M[node] = M[2*node+1];
		else
		M[node]=M[2*node+2];
	}
}

int RMQ(int node,int query_left,int query_right,int start,int end,int a[])
{
	if(query_left > end || query_right < start)
		return -1;
	else if(query_left >= start &&  query_right <= end)
		return M[node];
	else
	{
		int l = RMQ(2*node+1,query_left, (query_left+query_right)/2 ,start,end,a);
		int r = RMQ(2*node+2,(query_left+query_right)/2 + 1, query_right ,start,end,a);
		
		if(l==-1)
		return r;
		else if(r==-1)
		return l;
		
		if(a[l]<a[r])
		return l;
		else
		return r;
	}
}


int main()
{
	int a[]={2,6,1,4,8,3,7,9,5};
	create_binary_tree(0,0,sizeof(a)/sizeof(int)-1,a);

	int n = sizeof(a)/sizeof(int);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[M[i]]<<" "<<endl;
	}
	cout<<endl;
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			cout<<"Min Value Between "<<i<<" n "<<j<<" is : ";
			int x = RMQ(0,i,j,0,n-1,a);
			if(x!=-1)
			cout<<a[x]<<endl;
	    }
    }
	return 0;
}


