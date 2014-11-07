/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
*/

#include<bits/stdc++.h>
using namespace std;

int dp[150]; //storing 150 ugly numbers

// calcuate upto nth ugly numbers
int cal_number(int nth)
{
	
	dp[0]=1;
	int i2=0,i3=0,i5=0;
	
	for(int i=1;i<nth;i++)
	{	
	// finding the next ugly number
		int min_x = min ( min (dp[i2]*2 , dp[i3]*3 ), dp[i5]*5);
		
	/// finding wheather it came from i2,i3 or i5
		if(min_x == dp[i2]*2)
		i2++;
	    if(min_x == dp[i3]*3)
		i3++;
		if(min_x == dp[i5]*5)
		i5++;
		
		dp[i]=min_x;
	}
	
}

int main()
{
	cal_number(150);
	for(int i=0;i<150;i++)
	cout<<dp[i]<<endl;
	return 0;
}


