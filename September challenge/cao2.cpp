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

int get_monsters(int &n,int primes[])
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
	char a[50][50];
	//char a[5][7]={{'^','^','#','^','^','^','^'},{'^','^','#','^','#','^','#'},{'#','^','^','^','^','^','^'},{'^','^','#','^','^','#','^'},{'^','^','^','^','^','^','^'}};
	int row,col,t[50],b[50],l[50],r[50],min,count;
	int cases;
	int primes[95]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};
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
	//precommputing the l r t b :P
	//top n bottom
	for(int i=1;i<col;i++)
	{
		t[i]=0;
		b[i]=0;
		
			for(int j=0;j<row;j++)
			{
				if(a[j][i]=='^')
				{
					if(j<1)
					{
						t[i]++;
					}
					else if(j>1)
					b[i]++;
				}
			}
   }
   //left and right
   	for(int i=1;i<row;i++)
	{
		l[i]=0;
		r[i]=0;
		//if(a[1][i]=='^')
		{
			for(int j=0;j<col;j++)
			{
				if(a[i][j]=='^')
				{
					if(j<1)
					{
						l[i]++;
					}
					else if(j>1)
					r[i]++;
				}
			}
		}
   }

   
   //computing count
   for(int i=2;i<row;i++)
   {
   	   for(int j=2;j<col;j++)
   	   {
   	   	     //remaking top and bottom
   	   	  	    if(a[i-1][j]=='^')
   	   	  	    t[j]++;
   	   	  	    if(a[i][j]=='^')
   	   	  	    b[j]--;
   	   	  	 //remaking left and right
			   	if(a[i][j-1]=='^')
			   	l[i]++;
			   	if(a[i][j]=='^')
			   	r[i]--;
		  //cout<<"i j : "<<i<<j<<"\n";
		  //cout<<"t b l r : "<<t[j]<<b[j]<<l[i]<<r[i]<<"\n";
		
   	   	  if(a[i][j]=='^')
   	   	  {    
   	   	  	    min=min_cal(t[j],b[j],l[i],r[i]);
   	   	  	    cout<<"Min is : "<<min<<" i n j "<<i<<" "<<j <<"\n";
   	   	  	    count = count + get_monsters(min,primes);
   	   	  	    cout<<"Count is : "<<count<<"\n";
   	   	  	    
   	      }
   	   }
   }
   cases--;
   cout<<count<<"\n";
}
   
   return 0;
	
}
