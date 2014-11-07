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

vector< pair<int,int> > a;
vector<pair < int,int> > b;
vector<int> v(50000000);

int main()
{
	freopen("input.txt","r",stdin);
	int test;
	cin>>test;
	//test = read();
	int n,k,p;
	while(test--)
	{
		int l,r;
		cin>>n>>k>>p;
		//n=read();
		//k=read();
		//p=read();
	

		int _k=k;
		while(_k--)
		{
			cin>>l>>r;
			a.push_back(make_pair(l,r));
		}
		int ind=0;
		bool is_con = false;
		int _p=p;
		
		while(_p--)
		{
			cin>>l>>r;
			b.push_back(make_pair(l,r));
			if(l<=r)
			{
				for(int i=l;i<=r;i++)
				v[i]=ind;
				ind++;
		    }
		    else
		    {
		    
				for(int i=l;i<=n;i++)
				v[i]=ind;
				for(int i=1;i<=r;i++)
				v[i]=ind;
				ind++;
				is_con = true;
		    }
		}
		
		
		auto i=a.begin();
		int processed = 0;
		// now match
		
		while(i!=a.end())
		{
			int x = i->first;
			int y = i->second;
			
			for()
			int X = b[v[x]].first;
			int Y = b[v[y]].second;
			//cout<<"c : "<<x<<" "<<y<<" pos "<<v[x]<<" "<<v[y]<<" B "<<X<<" "<<Y<<endl;
			if(v[x]==v[y])
			{
				if(X<Y)
				{
					if(x<=y && x>= X  && y <=Y)
					{
						processed++;
						i++;
					}
					else
					break;
				}
				else if(X==Y)
				{
					if(x==y && x==X)
					{
						processed++;
						i++;
					}
					else
					break;
				}
				
				else if(X>Y && is_con)
				{
					if(x>=y && x>= X  && y <=Y)
					{
						processed++;
						i++;
					}
					else if(x<=y && x>=X && y>=X)
					{
						processed++;
						i++;
					}
					else if(x<=y && x<=Y && y<= Y)
					{
						processed++;
						i++;
					}
					else
					break;
				}
			}
			else
			break;
		}
		if(processed ==  a.size())
			printf("Yes\n");
		else
			printf("No\n");		
		a.clear();
		b.clear();	
	}
	return 0;
}


