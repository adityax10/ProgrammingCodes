#include<iostream>

using namespace std;

int main()
{
	//int a[50][50];
	char a[5][7]={{'^','^','#','^','^','^','^'},{'^','^','#','^','#','^','#'},{'#','^','^','^','^','^','^'},{'^','^','#','^','^','#','^'},{'^','^','^','^','^','^','^'}};
	int row,col,t,b,l,r,min,count;
	int primes[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	
	
	row=5;col=7;
	count=0;
	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			if(a[i][j]=='^')
			{
			t=b=l=r=0;
			//left n right 
			for(int k=0;k<col;k++)
			{
				if(a[i][k]=='^')
				{
					if(k<j)
					{
						l++;
					}
					else if(k>j)
					{
						r++;
					}
			   }  
			}
			//top and bottom
			for(int k=0;k<row;k++)
			{
				if(a[k][j]=='^')
				{
					if(k<i)
					{
						t++;
					}
					else if(k>i)
					{
						b++;
					}
				}
			}
			
			
			//computing min of the t,b,r,c
			if(t>=b)
			min=b;
			else
			min=t;
			if(min>r)
			min=r;
			if(min>l)
			min=l;
			
			//finding prime =>
			
			if(min>=2)
			{
				//cout<<"Counting for :"<<i<<" "<<j<<"\n";
				//cout<<"t b l r"<<t<<b<<l<<r<<"\n";
				count++;
			}
		    }
			
			
		}
	}
	 cout<<count<<"\n";
	 
	 return 0;
	
}
