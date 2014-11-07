#include<bits/stdc++.h>
using namespace std;

/*
There are n coins in a line.
 (Assume n is even). 
 Two players take turns to take a coin from one of the ends of the line until there are no more coins left. 
 The player with the larger amount of money wins.
*/

int cal_amount(int coins[],int i,int j)
{
	if(i>j)
	return 0;
	
	if(abs(i-j)==1)
	return max(coins[i],coins[j]);
	
	return max( coins[i] + min(cal_amount(coins,i+2,j),cal_amount(coins,i+1,j-1)),
				coins[j] + min(cal_amount(coins,i+1,j-1),cal_amount(coins,i+1,j-2))
			  );
}

int main()
{
	int coins[]={6,9,7,5};
	
	cout<<cal_amount(coins,0,sizeof(coins)/sizeof(int)-1);
	return 0;
}


