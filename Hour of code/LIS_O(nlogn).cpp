#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
using namespace std;

#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline unsigned long long int readLong() 
{
	int flag=1;
    unsigned long long int n = 0;
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

inline void writeInt(unsigned long long int x) 
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

int a[1000000],n;
int s[1000000];

void insert_binSearch(int r,int val)
{
	//cout<<" l=0 n r = "<<r<<endl;
	int l=0;
	while(r>l)
	{
		int mid=(l+r)/2;
		if(val < s[mid])
		r=mid-1;
		else if(val > s[mid])
		l=mid+1;
	}
	//cout<<"Replacing "<<s[r]<<"with "<<val<<endl;
	s[r]=val;
}

int LIS()
{
	int k=1;
	s[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i] > s[k-1])
		{
			s[k++]=a[i];
		}
		else
		{
		insert_binSearch(k-1,a[i]);	
		}
	}
	return k;
}

int main()
{
	n=readLong();
	for(int i=0;i<n;i++)
	{
		a[i]=readLong();
    }
    writeInt(LIS());
	return 0;
}


