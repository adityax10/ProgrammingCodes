#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline int readLong() 
{
	int flag=1;
    unsigned long long int n = 0;
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
long long int a_max_toright[100010];
long long int a_max_toleft [100010];
int cases,n,k;
inline long long int maxSubArraySum(unsigned int l)
{
   long long int max_so_far = a[l];
   long long int curr_max1 = a[l];
   for (unsigned int i = l+1; i <=n ; i++)
   {
        curr_max1 = max(a[i], curr_max1+a[i]);
        max_so_far = max (curr_max1,max_so_far);
   }
   return max_so_far;
}

inline long long int rmaxSubArraySum(unsigned int r)
{
   long long int max_so_far = a[r];
   long long int curr_max1 = a[r];
   for (unsigned int i = r-1; i >=1 ; i--)
   {
        curr_max1 = max(a[i], curr_max1+a[i]);
        max_so_far=max(curr_max1,max_so_far);
   }
   return max_so_far;
}

long long int find_sum()
{          
	long long int max_so_far,actual_max,ans;
	max_so_far =a[1];
	actual_max = a[1];
	ans=a[1]+a[k+2];
	//cout<<"ini : "<<ans<<endl;
	for(int i=2;i<=n-k-1;i++)
	{
		max_so_far = max(a[i],max_so_far+a[i]);
		actual_max = max(actual_max,max_so_far);
		if(i+k+1 <= n)
		ans=max(ans,actual_max+a_max_toright[i+k+1]);//
		//cout<<max_so_far<<" "<<actual_max<<" "<<ans<<endl;
	}
	return ans;
}

long long int r_find_sum()
{
	long long int max_so_far,actual_max,ans;
	max_so_far =a[n];
	actual_max = a[n];
	ans=a[n]+a[n-k-1];
	for(int i=n-1;i>=2+k;i--)
	{
		max_so_far = max(a[i],max_so_far+a[i]);
		actual_max = max(actual_max,max_so_far);
		if(i-k-1 >= 1)
		ans=max(ans,actual_max+a_max_toleft[i-k-1]);//
	}
	return ans;
}



int main()
{
	cases=readLong();
	while(cases--)
	{	                                 
		n=readLong();
		k=readLong();
		//ocin>>n>>k;
		for(unsigned int i=1;i<=n;i++)
		{
			a[i]=readLong();
			//cin>>a[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			a_max_toright[i]=maxSubArraySum(i);
			//cout<<"right "<<a_max_toright[i]<<endl;
		}
		for(int i=n;i>=1;i--)
		{
			a_max_toleft[i]=rmaxSubArraySum(i);
			//cout<<"left "<<a_max_toleft[i]<<endl;
		}
		cout<<max(find_sum(),r_find_sum())<<endl;
	}
	return 0;
}


