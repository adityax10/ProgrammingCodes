#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#include<bitset>
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


//BIT Binary Indexed Tree
class BIT{ 
	vector<int> *bitArray;
	int bitSize;
	//Initialisng BIT
	public :
	BIT(const vector<int> &x,int n)
	{
		bitSize = n+1;
		initaliseBIT(x);
	}
	//Making A BIT
	int initaliseBIT(const vector<int> &x)
	{
		//bitSize = x.size()+1;
		bitArray = new vector<int>(bitSize);
		
		for(int i=0;i<=bitSize;i++)
		(*bitArray)[i]=0;
		
		for(int i=1;i<bitSize;i++)
		{
			int val = x[i-1];
			int idx = i;
			
			while(idx<bitSize)
			{
				(*bitArray)[idx] += val;
				 idx += (idx&-idx);
			}
		}
		//cout<<endl;
	}
	
	void display()
	{
		for(int i=1;i<bitSize;i++)
		cout<<(*bitArray)[i]<<" ";
	}
	
	//Retrive an element a bit faster
	int retrieve_element(int x)
	{
		x++;
		int sum_x=0;
		if(x>0)
		{
			int y = x-(x&-x);
			sum_x=(*bitArray)[x];// this sum will be reduced
			//cout<<"VAl is "<<sum_x<<endl;
			x--;
			while(y!=x)
			{
				sum_x -= (*bitArray)[x];
				x -= x&-x;
			}
		}
		return sum_x;
	}
	
	//update a range
	void update_range(int s,int f,int val)
	{
		while(s<=f)
		{
			update_element(s,val);
			s++;
		}
	}
	
	// Updating an element in a BIT
	void update_element(int index,int val)
	{
		index++;
		while(index<bitSize)
		{
			(*bitArray)[index] += val;
			index+=(index&-index);
		//	cout<<"inc";
		}	
	}		
};

vector<int> x(1000005);
int temp[1000005];

int partition(int a[],int l,int r)
{
	int p=l,i=p,j,q=r,temp,x;
	
	x=a[p];
	
	for(j=p+1;j<=q;j++)
	{
	    if(x>=a[j])
	    {
	    i++;
	    temp=a[j];
	    a[j]=a[i];
	    a[i]=temp;
	    }
	}
	temp=a[p];
	a[p]=a[i];
	a[i]=temp;
	
	return i;
}


int get_median(int temp[],int l,int r,int n)
{
	if(l<=r)
	{
	int q = partition(temp,l,r);
	q=partition(temp,l,r);
//	cout<<"q = "<<q<<" "<<temp[q]<<endl;
	if(q==n/2)
	return temp[q];
	else
	{
	 return get_median(temp,l,q-1,n)+get_median(temp,q+1,r,n);
    }
    }
    return 0;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	n=read();
	k=read();            
	BIT b(x,n);
	int s,f;
	while(k--)
	{
		s=read();
		f=read();
		b.update_range(s-1,f-1,1);
	}
	//b.display();
	for(int i=0;i<n;i++)
	{
	temp[i]=b.retrieve_element(i);
	//cout<<temp[i]<<endl;
	}
	cout<<get_median(temp,0,n-1,n);
		
}


