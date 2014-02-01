#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<limits.h>
using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline long long int readLong() 
{
	int flag=1;
    long long int n = 0;
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

long long int a[100010];
long long int maxl,maxr,rmaxr,rmaxl;
unsigned int i_end,ir_end;

inline long long int maxSubArraySum(unsigned int l,unsigned int r)
{
   if(l==r)
   return a[l];
   
   long long int max_so_far = a[l];
   long long int curr_max1 = a[l];
   for (unsigned int i = l+1; i <=r ; i++)
   {
        curr_max1 = max(a[i], curr_max1+a[i]);
        if(curr_max1>max_so_far)
        {
        	max_so_far=curr_max1;
         	i_end=i;
        }
   }
   return max_so_far;
}
   
   
inline long long int rmaxSubArraySum(unsigned int l,unsigned int r)
{
   if(l==r)
   return a[l];
   
   long long int max_so_far = a[r];
   long long int curr_max1 = a[r];
   for (unsigned int i = r-1; i >=l ; i--)
   {
        curr_max1 = max(a[i], curr_max1+a[i]);
        if(curr_max1>max_so_far)
        {
        	max_so_far=curr_max1;
         	ir_end=i;
        }
   }
   return max_so_far;
}

int main()
{
	unsigned int n,k,cases; //k>=n-2 !
	cin>>cases;
	while(cases--)
	{	
		n=readLong();
		k=readLong();
		for(unsigned int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		i_end=1;
		ir_end=n;
		maxl=maxSubArraySum(1,n-k-1);
		//cout<<"M 1 :"<<maxl<<"end_i = "<<i_end<<endl;
		maxr=maxSubArraySum(i_end+k+1,n);
		//cout<<"M 2 :"<<maxr<<endl;
		
		rmaxr=rmaxSubArraySum(2+k,n);
		rmaxl=rmaxSubArraySum(1,ir_end-k-1);
		
	    cout<<max(maxl+maxr,rmaxl+rmaxr)<<endl;
	}
	return 0;
}


