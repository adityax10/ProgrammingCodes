#include <iostream>
#define MAXN 1000
#define MAXSIZE 10000
int M[MAXSIZE];

using namespace std;
 
//node is the index of the segment tree m, start and end are the index of the the array A
void BuildTree(int node,int start,int end,int A[])
{	
    if(start==end)
        M[node]=start;
    else
	{
        BuildTree(2*node+1,start,(start+end)/2,A);
        BuildTree(2*node+2,(start+end)/2+1,end,A);
        if(A[M[2*node+1]]<A[M[2*node+2]])
            M[node]=M[2*node+1];
        else
            M[node]=M[2*node+2];
    }   
}

//[start,end] => extremeties of the array A[]

int RMQ(int node,int start,int end,int s,int e,int A[])
{	
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

// driver programme
int main(){
    int A[4]  = {2,0,1,0};
    BuildTree(0,0,4-1,A);
    int s,e;
    for(int i=0;i<4;i++)
	cout<<A[M[i]]<<" ";
	cout<<endl;
	cout<<A[RMQ(0,0,4-1,0,1,A)];
	/*
    for(int s=0;s<4;s++)
    {
    	for(int e=s;e<4;e++)
    	 cout<<A[RMQ(0,0,8-1,s,e,A)]<<endl;
    }*/
   
    return 0;
}
