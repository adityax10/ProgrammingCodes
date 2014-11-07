#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline int readint() 
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
inline void writeInt(long long int x)
{
     int i = 20;
     char buf[21];
     buf[20] = '\n';
     bool flag =0;
     if(x<0)
     {
     x=-x;
     flag=1;
     }
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     if(flag)
     buf[--i]='-';
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

int a[301][301];
int num[301][301][10];
int temp[11];
bool xx[11];

int main()
{
	int q,n,i,j,x1,x2,y1,y2,ans;
	n=readint();
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		a[i][j]=readint();
		temp[a[i][j]]++;
		for(int k=1;k<=10;k++)
		num[i][j][k]=temp[k];
	    }
	}
	
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<" "<<i<<" "<<j<<" : ";
			for(int k=1;k<=10;k++)
			cout<<num[i][j][k]<<" ";
			cout<<"\n";
		}
	}*/
		
	q=readint();
	while(q--)
	{
		ans=0;
		x1=readint();
		y1=readint();
		x2=readint();
		y2=readint();
		if(x1==x2 && y1==y2)
		writeInt(1);
		else
		{
			long long int count=0;
			for(int j=x1;j<=x2;j++)
			{
				for(int i=1;i<=10;i++)
				{
				if(!xx[i] && ((num[j][y2][i] - num[j][y1][i])|| ((num[j][y2][i] - num[j][y1][i])==0 && num[j][y2][i] !=0 && (i==a[j][y1] || i==a[j][y2] ))))
				{
			    xx[i]=1;
			    //cout<<"Got : "<<i<<endl;
			    }
				}
			}
			for(int i=1;i<=10;i++)
			{
			if(xx[i]==1)
			count++;
			xx[i]=0;
		    }
			writeInt(count);
	   }
    } 
	return 0;
}


