#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

inline long long int maxSubArraySum(int a[],unsigned int l,unsigned int r)
{
   if(l==r)
   return a[l];
   
   int max_so_far = a[r];
   int curr_max1 = a[r],curr_max2=a[r];
   for (unsigned int i = l; i <=r ; i++)
   {
        curr_max1 = max(a[i], curr_max1+a[i]);
        //curr_max2=curr_max2+a[i];
        if(curr_max1>max_so_far /*|| curr_max2>max_so_far*/)
        {
        	max_so_far = curr_max1;
        	//max_so_far=max(curr_max1,curr_max2);
         	//ir_end=i;
        }
   }
   return max_so_far;
}


int main()
{
	int a[10]={5,5,-1,-2,5,-1,-3,-1,5,0};
	cout<<maxSubArraySum(a,0,9);
	return 0;
}


