#include<bits/stdc++.h>
using namespace std;

class Box{
	public:
	int l,b,h;
	Box()
	{
		l=0;
		b=0;
		h=0;
	}
	Box(int _l,int _b,int _h)
	{
		l=_l;
		b=_b;
		h=_h;
	}
};

int comp(const Box &a,const  Box &b)
{
	return a.l*a.b > b.l*b.b;
}


int cal_dp(Box box[],int n)
{
	vector<int> dp(3*n);
	for(int i=0;i<3*n;i++) 
	dp[i]=0;
	// for every possible
	vector<Box> B( 3*n );
	
	for( int i = 0 ; i < n ; i++ )
	{
		// orignal orientration
        // h as h
		B[3*i]=box[i];
	//	cout<<B[i].l<<" "<<B[i].b<<" "<<B[i].h<<endl;
        // h as l
        B[3*i+1].h=box[i].l;
        B[3*i+1].b=max(box[i].b,box[i].h);
        B[3*i+1].l=min(box[i].b,box[i].h);
	//	cout<<B[i+1].l<<" "<<B[i+1].b<<" "<<B[i+1].h<<endl;
        // h as b
        B[3*i+2].h=box[i].b;
		B[3*i+2].b=max(box[i].l,box[i].h);
        B[3*i+2].l=min(box[i].l,box[i].h);
	}
	
	sort(B.begin(),B.end(),comp);
	
	dp[0] = B[0].h;
	int max_height=INT_MIN;
	for( int  i=1 ; i < 3*n ; i++ )
	{
		for( int j = 0 ; j < i ; j++ )  
		{
			if( B[i].l < B[j].l && B[i].b < B[j].b )
			dp[i] = max(dp[i],dp[j]+B[i].h);
			else
			dp[i] = max(dp[i],dp[i-1]);
		}
		max_height = max (max_height , dp[i]);
	}
	return max_height;
}

int main()
{
	
	Box B[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	
	cout<<cal_dp(B,sizeof(B)/sizeof(Box));
	return 0;
}


