#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txy.cpp","r",stdin);
    ios_base::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    int x,y;
    map<int,int> mp[n+1];
    int v[n+1][2];
    for(int i=0;i<=n;i++)
    {
        v[i][0]=0;
        v[i][1]=0;
    }
    while(p--)
    {
        cin>>x>>y;
        mp[x][y]++;
        if(y==1)
           v[x][0]++;
        else if(y==m)
            v[x][1]++;
    }

  /*  for(int i=1;i<=n;i++)
    {
        map<int,int>m_p =  mp[i];
        for(map<int,int> :: iterator j=m_p.begin() ; j!=m_p.end() ; j++)
            cout<<j->first<<","<<j->second<<" ";
        cout<<endl;
    }*/

    for(int i=1;i<=n;i++)
    {
        map<int,int>m_p =  mp[i];
        if(m==1)
        {
        	cout<<0<<endl;
        }
        else if(m_p.size()==0)
        {
            cout<<m-1<<endl;
        }
        else
        {
            bool flag = 0;
            for(map<int,int> :: iterator j=m_p.begin() ; j!=m_p.end() ; j++)
            {
                int y = j->first;
                int y_f = j->second;
                map<int,int> :: iterator j_n = j;
                j_n++;
                if(j_n!=m_p.end())
                {
                    int y_n = j_n->first;
                    int y_n_f = j_n->second;
                    if((y!=m &&  y+y_f > y_n + y_n_f)) // 1 4 7 8 10
                    {
                        flag=1;
                        break;
                    }
                    if(y!=m && y+1!=y_n && y+y_f > y+1)
                    {
                        flag=1;
                        break;
                    }
                }
                else if(y!=m && y+y_f > y+1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            cout<<-1<<endl;
            else
            {
                cout<<m-1-v[i][0]+v[i][1]<<endl;
            }
        }
    }
    return 0;
}

