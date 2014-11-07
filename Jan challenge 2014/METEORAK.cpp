#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
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
     buf[20] = ' ';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != ' ');
}


int max_area_in_histogram(int *a,int n)
{
	vector<int> s;
	int max_area=0,area;
	int i=0;
	while(i<n)
	{
		if(s.empty() || a[i] > a[s.back()])
		s.push_back(i++);
		else
		{
			int x = s.back();
			s.pop_back();
			area = s.empty()?a[x]*i :a[x]*(i-s.back()-1);
			max_area=max(area,max_area);
			//cout<<"Area : "<<area<<"Max_Area "<<max_area<<endl;
		}
	}
	while(!s.empty())
	{
		int x = s.back();
			s.pop_back();
			area = s.empty()?a[x]*i :a[x]*(i-s.back()-1);
			max_area=max(area,max_area);
	}
	return max_area;
}


int ar[1002][1002];
int max_area[1002][1002];
int temp[1002];

int main()
{
	int n,m,k,q;

	n = read();
	m = read();
	k = read();
	while(k--)
	{
		int x = read();
		int y = read();
		ar[x-1][y-1]=-1;
	}

	for(int j = 0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(i==0 && ar[i][j]!=-1)
			{
				ar[i][j]=1;
				continue;
			}
			if(ar[i][j] !=-1)
			{
				if(ar[i-1][j]!=-1)
				ar[i][j]= ar[i-1][j]+1;
				else
				{
				ar[i][j] = 1;
			    }
		   }
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if(ar[i][j]==-1)
		ar[i][j]=0;
	}

	for(int j=0;j<n;j++)
	{
		max_area[0][j] = max_area_in_histogram(ar[j],m);
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
		if(i==j)
		{
			int c=0;
			int maxc=0;
			for(int z=0;z<m;z++)
			{
				if(ar[i][k]==-1)
				c=0;
				else
				{
				c++;
				maxc=max(maxc,c);
			    } 
			}
			max_area[i][j]=maxc;
			continue;
		}		
			
		for(int k = 0;k<m;k++)
		{
		
        temp[k]= (ar[i][k]!=0)?ar[j][k]-ar[i][k]+1 : ar[j][k];
        if(temp[k]<0)
        temp[k]=0;
        //cout<<temp[k]<<" ";
        }
        //cout<<endl;
		max_area[i][j] = max_area_in_histogram(temp,m);
		//cout<<"i "<<i<<"j "<<j<<" : "<<max_area[i][j]<<endl;
		}
	}
	
	q = read();
	while(q--)
	{
		int l = read();
		int h = read();
		cout<<max_area[l-1][h-1]<<endl;
	}
	return 0;
}


