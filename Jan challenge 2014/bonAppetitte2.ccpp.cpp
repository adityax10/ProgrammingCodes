#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
typedef unsigned long long int ulli;

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

map<int,vector< pair< ulli,ulli> > > slot;

bool cmp_fx(const pair< ulli,ulli> i,const pair< ulli,ulli> j)
{
	//if(i.first!=j.first)
	//return i.first < j.first;
	//else
	{
		return i.second < j.second;
	}
}

void insert_binSearch(ulli val,vector<ulli> &ans)//slot index => si
{
	//cout<<" l=0 n r = "<<r<<endl;
	ulli l=0;
	ulli r = ans.size()-1;
	while(r>l)
	{
		int mid=(l+r)/2;
		if(val < ans[mid])
		r=mid-1;
		else if(val > ans[mid] )
		l=mid+1;
	}
	//cout<<"Replaced "<<ans[r]<<" with "<<val<<endl;
	ans[r] = val;
}

inline void write(long long int x) 
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

vector<ulli> ansi;

ulli LIS(ulli si)
{
	ulli k=0;
	auto v = slot[si];
	ansi.push_back(v[0].second);
	//cout<<"Initially : pushed "<<ansi[0]<<endl;
	for(ulli i = 1;i<v.size();i++)
	{
		ulli x = v[i].second;
		ulli y = v[i].first;
		if(ansi.back()<x &&  y!= v[k].first && y >= v[k].second)
		{
		//	cout<<"Pushed back :"<<x<<endl;
			ansi.push_back(x);
			k = i;
		}
		else if(ansi.back() > x)
		{
			//cout<<"Replacing \n";
			insert_binSearch(x,ansi);
		}
	}
	//cout<<"return : "<<ans.size()<<endl;
	ulli siz = ansi.size();
	if(siz!=0)
	ansi.clear();
	return siz;
}

int main()
{
	ulli s,f,i,n,k;
	int cases;
	cases = readLong();
	while(cases--)
	{
		n = readLong();
		k =readLong();
		for(ulli x =1;x<=n;x++)
		{
			s= readLong();
			f =readLong();
			i =readLong();
			slot[i].push_back(make_pair(s,f)); // ?
		}
		ulli ans = 0;
		if(n!=0)
		{
			auto i = slot.begin();
			while(i!=slot.end())
			{
				vector< pair< ulli,ulli> > &v = (*i).second;
				//if(v.size()!=0) //1R
				{
				sort(v.begin(),v.end(),cmp_fx);
				//cout<<"INdex "<<i->first<<endl;
				//for(int i = 0;i<v.size();i++)
				//cout<<v[i].first<<" "<<v[i].second<<endl;
				ans = ans +LIS((*i).first);
			    }
			    i++;
			}
	    } 
		write(ans);
		slot.clear();
	}
	return 0;
}


