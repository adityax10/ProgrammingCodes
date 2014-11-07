#include<iostream>

using namespace std;

int min_cal(int &t,int &b,int &l,int &r)
{
	int min;
	    if(t>=b)
		min=b;
		else
		min=t;
		if(min>r)
		min=r;
		if(min>l)
		min=l;
		return min;
}

int primes[95]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};

int get_monsters(int &n)
{
	int l=0;
	int r=94;
	int mid;
	if(n<2)
	return 0;
	while(l<r)
	{
		mid =(l+r)/2;
		if(n == primes[mid])
		return mid+1;
		else if( n > primes[mid])
		l=mid+1;
		else
		r=mid-1;
	}
	return l+1;
}

int main()
{
	//char a[5][7]={{'^','^','#','^','^','^','^'},{'^','^','#','^','#','^','#'},{'#','^','^','^','^','^','^'},{'^','^','#','^','^','#','^'},{'^','^','^','^','^','^','^'}};
	int row,col,t,b,l,r,min,count;
	char a[500][500];
	int cases;
	
	cin>>cases;
	while(cases > 0)
	{
		cin>>row>>col;
		
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			cin>>a[i][j];  
		}
		count=0;
		
		for(int i=2;i<row;i++)
		{
			for(int j=2;j<col;j++)
			{
				if(a[i][j]=='^')
				{
				char k;
				int x_t = i;
				int y_t = j;
				t=b=l=r=0;
				//left
				while((k=a[i][--y_t])!='#' && y_t>=0)
				{
			        l++;
			    }
			    //right
			    y_t=j;
			    while((k=a[i][++y_t])!='#' && y_t<col)
				{
			        r++;
			    }
			    //top
			    while((k=a[--x_t][j])!='#' && x_t>=0)
			    {
			    	t++;
			    }
			    //bottom
			    x_t=i;
			    while((k=a[++x_t][j])!='#' && x_t<row)
			    {
			        b++;
			    }
				
				//finding prime =>
				if(a[i][j]=='^')
	   	   	    {      
	   	   	  	    min=min_cal(t,b,l,r);
	   	   	  	  // cout<<"Min is : "<<min<<" i n j "<<i<<" "<<j <<"\n";
	   	   	  	    count = count + get_monsters(min);
	   	   	  	    //cout<<"Count is : "<<count<<"\n";
	   	        }
			    }
			}
		}
		   cases--;
		   cout<<count<<"\n";
   }
   
   return 0;
	
}
