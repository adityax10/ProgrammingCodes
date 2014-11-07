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
};
entry L[200];

int cmp(const entry &a,const entry &b)
{
	return (a.er[0]==b.er[0])?(a.er[1]<b.er[1]):(a.er[0]<b.er[0]);
}

//int pis[20]; // position of suffix entry in sorted order
int P[20][20];// P(k, i) is the index of substring A.substr(i, 2^k) in sorted order.

int stp,cnt; // step, count =>2,4,8,16..
int n;
string s;
//int LCP[20];

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

int main()
{
	s = "mississi";
	n=s.size();
	for(int i=n-1;i>=0;i--)
	{
		P[0][i] = s[i]-'a';
	}
	
	
	for(stp=1,cnt=1;cnt < n;cnt*=2,stp++)
	{
		for(int i=0;i<n;i++)
		{
			L[i].er[0] = P[stp-1][i];
			L[i].er[1] = ((i+cnt)<n)?P[stp-1][i+cnt]:-1;
			L[i].p = i; // starting index of each suffix
		}
		// sort the entires
		sort(L,L+n,cmp);
		
		for(int i=0;i<n;i++)
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
	
	//int s=1;
	//int e=4;
	//cout<<Find_LCP(s,e)<<endl;
	
	int len=-1,temp_len;
	//preparing input array for RMQ
	for(int i=0;i+1<n;i++)
	{
		temp_len =  Find_LCP(L[i].p,L[i+1].p);
		int b = max(L[i].p,L[i+1].p);
		int a = min(L[i].p,L[i+1].p);
	}
	cout<<"len : "<<len<<endl;
	
	return 0;
}


