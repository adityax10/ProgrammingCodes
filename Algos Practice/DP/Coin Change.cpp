#include<bits/stdc++.h>
using namespace std;

int ways_to_change(int x,int c[],int i)
{
	cout<<"ways_to_change( "<<x<<" , "<<i<<" )\n";
//	int y;
//	cin>>y;
	if(x==0)
	return 1;
	
	if( i<0 || x<0 )
	return 0;
	
	if(x-c[i]<0)
	return ways_to_change(x,c,i-1);
	
	else
	// include ith                            // exclude ith
	return  ways_to_change(x-c[i],c,i) + ways_to_change(x,c,i-1);
	
}

int main()
{
	int c[]={1,2,3,4};
	int x = 4;
	cout<<ways_to_change(x,c,sizeof(c)/sizeof(int)-1);
	return 0;
}
