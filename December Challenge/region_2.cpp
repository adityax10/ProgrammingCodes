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

long long int max(long long int i,long long int j,long long int k)
{
	long long int temp;
	temp = i>j?i:j;
	return temp>k?temp:k;
}

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
long long int l[100010];
long long int r[100010];

unsigned int i_end,i_end_p,ir_end,ir_end_p,k,n;

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
        	i_end_p=i_end;
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
        	ir_end_p=ir_end;
         	ir_end=i;
        }
   }
   return max_so_far;
}

long long int in_interval_checker(long long int maxv,int l,int r)
{
	if(l<1 || r< 1 || l-r-1 < k || l>n || r>n)
	return LONG_MIN;
	
	for(int i=l+1;i<r;i++)
	{
		if(a[i]<0)
		{
			maxv+=-(a[i]);
		}		
	}
	return maxv;
}


int main()
{
	unsigned int cases; //k>=n-2 !
	long long int maxl,maxl_in,maxr_in,maxr,rmaxr,rmaxr_in,rmaxl,rmaxl_in;
	cin>>cases;
	while(cases--)
	{	
		n=readLong();
		k=readLong();
		for(unsigned int i=1;i<=n;i++)
		{
			a[i]=readLong();
		}
		
		i_end=1;
		ir_end=n;
		maxl=maxSubArraySum(1,n-k-1);
		maxl_in=in_interval_checker(maxl,i_end_p,i_end);
		//cout<<"M 1 :"<<maxl<<"end_i = "<<i_end<<endl;
		maxr=maxSubArraySum(i_end+k+1,n);
		maxr_in=in_interval_checker(maxr,i_end_p,i_end);
		//cout<<"M 2 :"<<maxr<<endl;
		maxl=max(maxl+maxr,maxl_in,maxr_in);
		
		rmaxr=rmaxSubArraySum(2+k,n);
		rmaxr_in =in_interval_checker(rmaxr,ir_end,ir_end_p);
		
		rmaxl=rmaxSubArraySum(1,ir_end-k-1);
		rmaxl_in =in_interval_checker(rmaxl,ir_end,ir_end_p);
		
		rmaxl=max(rmaxl+rmaxr,rmaxr_in,rmaxl_in);
		cout<<(maxl>rmaxl?maxl:rmaxl)<<endl;
		
	}
	return 0;
}


