#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int M[100];

// Step 1
// Building the segmented tree out of array
void build_segmented_tree(int node,int start,int end,int A[]){
    if(start==end)
        M[node]=start;
    else{
        build_segmented_tree(2*node+1,start,(start+end)/2,A);
        build_segmented_tree(2*node+2,(start+end)/2+1,end,A);
        if(A[M[2*node+1]]<A[M[2*node+2]])
            M[node]=M[2*node+1];
        else
            M[node]=M[2*node+2];
    }
}

 
int RMQ(int node,int start,int end,int s,int e,int A[]){
    if(s<=start && e>=end)
        return M[node];
    else if(s>end || e<start)
        return -1;
    int q1 = RMQ(2*node+1,start,(start+end)/2,s,e,A);
    int q2 = RMQ(2*node+2,(start+end)/2+1,end,s,e,A);
    if(q1==-1)
        return q2;
    else if(q2==-1)
        return q1;
    if(A[q1]<A[q2])
        return q1;
    return q2;
}


int main()
{
	int a[]  = {7,1,2,3,41,8,34,67};
	int n = sizeof(a)/sizeof(int);
	build_segmented_tree(0,0,n-1,a);
	
	for(int i=0;i<n;i++)
	cout<<a[M[i]]<<" ";
	
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


