#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<int> c;

int included_c[41];

int total_price;
int turns;

void print_bool(int n)
{
	for(int i=0;i<n;i++)
	cout<<included_c[i]<<" ";
	cout<<endl;
}

void cal_dp(int price,int i,int m)
{
    if( i > p.size()-1 )
    return;

    if( m <= 0 && i == p.size()-1 )
    {
        //cout<<"Adding "<<price<<endl;
        total_price+=price;
        turns++;
        return;
    }

    if(  ( m <= 0) ||  ( i!=p.size()-1 && !included_c[c[i]] )  )
    {
        //cout<<"Including i= "<<i<<" m "<<m-1<<" e : "<<c[i]<<" "<<p[i]<<endl;
        included_c[c[i]]++;
//        print_bool(p.size());
        cal_dp( price+p[i] , i+1 , m-1 );
        included_c[c[i]]--;
    }
// cout<<"Removing i = "<<i<<" m "<<m<<" e : "<<c[i]<<" "<<p[i]<<endl;
//    print_bool(p.size());
    cal_dp( price , i+1 , m );
}

int main()
{
    freopen("./in.txt","r",stdin);
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,m;
        cin>>n>>m;
        p.resize(n+1);
        c.resize(n+1);
        int i=0;
        while(n--)
        {
            cin>>c[i]>>p[i];
//            cout<<c[i]<<" "<<p[i]<<endl;
            i++;
        }
        c[i]=0;
        p[i]=0;
        total_price=0;
        turns=0;
        memset(included_c,0,sizeof(included_c));
        cal_dp(0,0,m);
        //cout<<turns<<endl;
		cout<<fixed<<setprecision(10)<<(double)total_price/turns<<endl;
    }
    return 0;
}


