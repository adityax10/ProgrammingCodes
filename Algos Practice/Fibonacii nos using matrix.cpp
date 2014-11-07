#include<bits/stdc++.h>
using namespace std;

void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
// O(n) approach
int cal_dp_fibo(int n)
{
	int f[2][2] = { { 1 , 1 } , { 1 , 0  } } ;
	int s[2][2] = { { 1 , 1 } , { 1 , 0  } } ;
	
	for(int i=1;i<n;i++)
	{
		multiply(f,s);
	}
	return f[0][0];
}

int main()
{
	cout<<cal_dp_fibo(5);
	return 0;
}


