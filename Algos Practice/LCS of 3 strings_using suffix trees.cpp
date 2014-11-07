
//Suffix array Implementation
// n log(n)*log(n) approach for building suffix array
#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

struct entry
{
	int er[2]; // er[0] => sort index of the suffix entry | er[1]=> sort index of the suffix entry staring at 2,4,8,16.. indexes in the current enrty
	int p; // starting postion of the  entry in the string
	int si; //string index
};
entry L[200];

int cmp(const entry &a,const entry &b)
{
	return (a.er[0]==b.er[0])?(a.er[1]<b.er[1]):(a.er[0]<b.er[0]);
}

int pis[20]; // position of suffix entry in sorted order
int P[20][20];// P(k, i) is the index of substring A.substr(i, 2^k) in sorted order.

int stp,cnt; // step, count =>2,4,8,16..
int n;
int LCP[20];

void print_string(int i,int j)
{
	for(int x=i;x<j;x++)
	cout<<s[x];
	cout<<endl;
}

// finding longest common prefix of the suffiexs starting at postion x &  y;
// log(n) approach
int Find_LCP(int x,int y)
{
	int ans= 0;
	
	for(int k = stp-1 ;k>=0 && x<n && y<n ;k--)
	{
		//sort index is same if first k characters are same
		if(P[k][x]==P[k][y])
		{
		ans += 1<<k;
		//now finding characters same in the remaining string
		x += 1<<k;
		y += 1<<k;	
	    }
	}
	return ans;
}

#define MAXN 1000
#define MAXSIZE 10000
int M[MAXSIZE];

//node is the index of the segment tree m, start and end are the index of the the array A
void BuildTree(int node,int start,int end,int A[]){
    if(start==end)
        M[node]=start;
    else{
        BuildTree(2*node+1,start,(start+end)/2,A);
        BuildTree(2*node+2,(start+end)/2+1,end,A);
        
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
	string s1 = "aababc";
	string s2 = "aaababca";
	string s3 = "abababca";
	
	n=max(max(s1.size(),s2.size()),s3.size());
	int N = s1.size()+s2.size()+s3.size();
	int ind=0
	
	for(int i=0;i<s1.size();i++)
	{
	P[0][ind++]=s1[i]-'a';
    }
	
	for(int i=0;i<s2.size();i++ )
	P[0][ind++] = s2[i] -'a';
	
	for(int i=0;i<s3.size();i++ )
	P[0][ind++] = s3[i] - 'a';
	
	for(stp=1,cnt=1;cnt < n;cnt*=2,stp++)
	{
		for(int i=0;i<N;i++)
		{
			L[i].er[0] = P[stp-1][i];
			L[i].er[1] = ((i+cnt)<n)?P[stp-1][i+cnt]:-1;
			L[i].p = i; // starting index of each suffix
		}
		// sort the entires
		sort(L,L+N,cmp);
		
		for(int i=0;i<N;i++)
		{
		cout<<L[i].p<<" :  ( "<<L[i].er[0]<<" , "<<L[i].er[1]<<" ) "<<P[stp-1][i]<<" | ";
		print_string(L[i].p,n);
		}
		cout<<endl;
		
		//update the P[stp][]  for the next stp
		for(int i=0;i<n;i++)
		{
            P[stp][L[i].p] =i> 0 && L[i].er[0]==L[i-1].er[0] && L[i].er[1] == L[i- 1].er[1] ? P[stp][L[i-1].p] : i;
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<L[i].p<<" :  ( "<<L[i].er[0]<<" , "<<L[i].er[1]<<" ) "<<P[stp-1][i]<<" | ";
		print_string(L[i].p,n);
	}
	
	// for LCP
	// nlog(n)
	
	int s=1;
	int e=4;
	
	cout<<Find_LCP(s,e)<<endl;
	
	//preparing input array for RMQ
	for(int i=0;i+1<n;i++)
	{
		pis[L[i].p]=i;
		LCP[i]=Find_LCP(L[i].p,L[i+1].p);
		cout<<" LCP "<<LCP[i]<<endl;
	}
	pis[L[n-1].p]=n-1;
	
	// now to answer queries..in.. O(1) using RMQ of LCP[]
	BuildTree(0,0,n-2,LCP);
//	for(int i=0;i<=n-2;i++)
//	cout<<LCP[M[i]]<<endl;
	
	//cout<<pis[s]<<" "<<pis[e]<<endl;
	if(pis[s]>pis[e])
	swap(s,e);
	cout<<LCP[RMQ(0,0,n-2,pis[s],pis[e]-1,LCP)];
	
	return 0;
}


