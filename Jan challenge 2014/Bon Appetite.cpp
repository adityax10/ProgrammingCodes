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
typedef int ulli;

inline long long int readLong() 
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

struct s
{
	public :
    vector< pair< ulli,ulli> > v;
};
map<int,s> slot;

bool cmp_fx(const pair< int,int> i,const pair< int,int> j)
{
	if(i.first!=j.first)
	return i.first < j.first;
	else
	{
		return i.second < j.second;
	}
}

void insert_binSearch(int val,vector<int> &ans)//slot index => si
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

vector<ulli> ansi;

ulli LIS(ulli si)
{

	ulli k=0;
	ansi.push_back(slot[si].v[0].second);
	for(ulli i = 1;i<slot[si].v.size();i++)
	{
		ulli x = slot[si].v[i].second;
		ulli y = slot[si].v[i].first;
		if(ansi.back()<x &&  y!= slot[si].v[k].first && y >= slot[si].v[k].second)
		{
			//cout<<"Pushed back :"<<x<<endl;
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
	return ansi.size();
}

int main()
{
	int s,f,i,n,k;
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
			slot[i].v.push_back(make_pair(s,f));
		}
		int ans = 0;
		if(n!=0)
		for(int x =1;x<=k;x++)
		{
			sort(slot[x].v.begin(),slot[x].v.end(),cmp_fx);
		//	for(int i = 0;i<slot[x].v.size();i++)
		//	cout<<slot[x].v[i].first<<" "<<slot[x].v[i].second<<endl;
			ans = ans +LIS(x);
			ansi.clear(); 
		//	slot[x].v.clear();
		}
		printf("%d\n",ans);
		slot.clear();
	}
	return 0;
}


