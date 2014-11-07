#include <iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
using namespace std;
long long M[500005];
long long A[500005];
inline long long read() 
{
	int flag=1;
    long long n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
              c=GETCHAR();
              if(i==0&&c=='-') parity=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
              i++;
    }
    return parity*n;
}
 
//node is the index of the segment tree m, start and end are the index of the the array A
void BuildTree(long long node,long long start,long long end){
    if(start==end)
        M[node]=start;
    else{
        BuildTree(2*node+1,start,(start+end)/2);
        BuildTree(2*node+2,(start+end)/2+1,end);
        if(A[M[2*node+1]]>A[M[2*node+2]])
            M[node]=M[2*node+1];
        else
            M[node]=M[2*node+2];
    }
}
 
long long RMQ(long long node,long long start,long long end,long long s,long long e){
    if(s<=start && e>=end)
        return M[node];
    else if(s>end || e<start)
        return -1;
    long long q1 = RMQ(2*node+1,start,(start+end)/2,s,e);
    long long q2 = RMQ(2*node+2,(start+end)/2+1,end,s,e);
    if(q1==-1)
        return q2;
    else if(q2==-1)
        return q1;
    if(A[q1]>A[q2])
        return q1;
    return q2;
}


int main(){
    long long n,_n,m,i=0;
    long long s,e,count=0;
    
    n = read();
    m = read();
    _n=n;
    while(_n--)
    A[i++] = read();
    
    BuildTree(0,0,n-1);
    
    while(m--)
    {
    	s = read();
    	e = read();
    	s--;
    	e--;
    	if(e-s==1)
    	count++;
    	else
    	{
    	long long x = A[RMQ(0,0,n-1,s+1,e-1)];
    	//cout<<"MAx b/w "<<s<<" "<<e<<" "<<x<<endl;
    	if(x<=A[s])
    	count++;
        }
    }
    cout<<count<<endl;
    
   
    return 0;
}
