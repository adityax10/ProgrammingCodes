#include<iostream>
#include<vector>

using namespace std;

int printPowerSet(vector<int> &set, int set_size,int mod)
{
	//cout<<"in"<<set_size;
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = 1<<set_size;
    int counter, j;
    long long x =0,ans=0;
    /*Run from counter 000..0 to 111..1*/
    for(counter = 1; counter < pow_set_size; counter++)
    {
      for(j =0 ; j < set_size ; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            {
            	int y = set[j];
				x = x*10 + y;
            }
            //cout<<x<<endl;
       }
       ans += x%mod;
       x=0;
    }
    return ans%mod;
}
vector<int> s;
/*Driver program to test printPowerSet*/
int main()
{
	long long int num,mod;
	int cases;
	cin>>cases;
	while(cases--)
	{
		cin>>num;
		cin>>mod;
		while(num)
		{
			int x = num%10;
			num = num /10;
			s.push_back(x);
		}
		//cout<<"do";
		cout<<printPowerSet(s,s.size(),mod)<<endl; 
		s.clear();
	}
    return 0;
}
