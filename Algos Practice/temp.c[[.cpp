#include<bits/stdc++.h>
using namespace std;

int sum(int A[], int from, int to) {
  int total = 0;
  for (int i = from; i <= to; i++)
    total += A[i];
  return total;
}
 
int partition(int A[], int n, int k) {
  if (k == 1)
    return sum(A, 0, n-1);
  if (n == 0)
    return A[0];
 
  int best = INT_MAX;
  for (int j = 0; j < n; j++)
    best = min(best, max(partition(A, j, k-1), sum(A, j, n-1)));
 
  return best;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	cout<<partition(a,9,3);
	return 0;
}


