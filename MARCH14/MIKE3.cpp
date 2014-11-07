#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
using namespace std;

inline int read() 
{
	int flag=1;
    int n = 0;
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

inline void write(int x) 
{
     int i = 20;
     char buf[21];
     buf[20] = '\n';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

vector<vector<int>> v;

int set_bits(int n)
{
	int set=0;
	while(n)
	{
		if(n&1)
		set++;
		n=n>>1;
	}
	return set;
}

int cal_max_indpendent_sets(int n,int m)
{
	int max_offers=0;	
	for(int i=1 ;i < 1<<m ;i++) ///  every i has a posssible combination of  subsets
	{
		//cout<<"Comb "<<i<<endl;
		//optimisiing measure : 
		// Checking if the number of set bite in i is > max_offers found so far
		if(set_bits(i)>max_offers)
		{
			int count =0;
			bool intersecting = 0;
			map<int,bool> map;
			for(int j=0;j < m;j++)// checking each combination
			{
				if(i & (1<<j))
				{
					// seeing jth subset
					for(int z = 0;z< v[j].size(); z++)
					{
						if(map[v[j][z]]==0)
						{
							map[v[j][z]]=1;
						}
						else
						{
							intersecting  = 1;
							break;
						}
					}
					if(!intersecting)
					{
						count++;
					}
					else
					{
						break;
					}
				}
		    }
		    if(!intersecting)
		    {
		     if(max_offers < count)
		     {
		     	max_offers = count;
		     	cout<<"i : "<<i<<endl;
		     }
		    	//cout<<"max_offers "<<max_offers<<endl;
		    }
		}
	}
	
	return max_offers;
}

int main()
{
	freopen("C:\\Users\\Aditya Vats\\Downloads\\Code Chef\\Tester\\test.txt","r",stdin);
	int n,m;
	n = read();
	m = read();
	int _m = m;
	while(_m--)
	{
		int x =  read();
		vector<int> v_in;
		while(x--)
		{
			int val;
			val = read();
			v_in.push_back(val);
	    }
	    v.push_back(v_in);
	   // cout<<"read 1\n";
	}
	write(cal_max_indpendent_sets(n,m));

	return 0;
}


