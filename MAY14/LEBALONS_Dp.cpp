#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int n_max = 40;
ull dp[n_max + 1][n_max + 1];
vector<int> c[n_max + 1];

ull cal_dp(int color_to_remove,int n,int m)
{
	for(int i=0;i<=n_max;i++)
	{
		for(int j=0;j<=n_max;j++)
		dp[i][j]=0;
	}
  dp[0][0] = 1;
  
  for(int i = 1; i <= n_max; i++)
  {
	dp[i][0] = 1;
	if(color_to_remove == i || c[i].size() == 0)
	{
	  	for(int j = 1; j <= n_max; j++)
		dp[i][j] = dp[i - 1][j];
	}
	else 
	{
	  int x = c[i].size();
	  for(int j = 1; j <= n_max; j++)
	  {
	    dp[i][j]+=dp[i-1][j-1]*((1LL<<x)-1)+dp[i-1][j];
	  }
	}
  }
  /*for(int i=0;i<=n_max;i++)
  {
  	for(int j=0;j<=n_max;j++)
  	cout<<dp[i][j]<<" ";
  	cout<<endl;
  }*/
  
  ull times = 0;
  if(color_to_remove==0)
  {
  for(int i = m ; i <= n_max; i++)
    times += dp[n_max][i];
  }
  else
  {
    for(int i = m-1 ; i <= n_max; i++)
    times += dp[n_max][i];	
  }
  return times;
}
 
int main()
{	
  freopen("./in.txt","r",stdin);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int cases;
  int n,m;
  cin >> cases;
  while(cases--)
  {
    cin >> n >> m;
    for(int i = 0; i <= n_max; i++)
      c[i].clear();
    for(int i = 0; i < n; i++)
	{
      int color, price;
      cin >> color >> price;
      c[color].push_back(price);
    }
    ull total_sum=0;
    for(int i=1;i<=n_max;i++)
	{
      if(c[i].size()==0)
      {
	  continue;
      }
      else
	  {
      ull t = cal_dp(i,n,m)*(1LL<<(c[i].size()-1));
      vector<int> v = c[i];
      for(vector<int> :: iterator a=v.begin();a!=v.end();a++)
        total_sum+=t*(*a);
      }
    }
    cout << total_sum*1.0/cal_dp(0,n,m) << endl;
  }
  return 0;
}


