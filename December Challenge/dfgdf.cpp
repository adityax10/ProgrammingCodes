#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}


int n_maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
         max_ending_here = 0;
 
     /* Do not compare for all elements. Compare only  
        when  max_ending_here > 0 */
     else if (max_so_far < max_ending_here)
         max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main()
{
	//int a[10]={5,5,-1,-2,5,-4,-1,-1,50,0};
	//int a[10]={5,5,-1,-2,5,-1,-3,-1,20,0};
	//int a[10]={5,5,-1,-2,5,-1,-3,-4,5,0};
	int a[8]={5, 5 ,-1 ,-2 ,3 ,-1,2,-2};
	cout<<maxSubArraySum(a,8)<<" ";
	//cout<<n_maxSubArraySum(a,10);
	return 0;
}


