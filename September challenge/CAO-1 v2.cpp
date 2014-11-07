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

int main()
{
	char a[50][50];
	//char a[5][7]={{'^','^','#','^','^','^','^'},{'^','^','#','^','#','^','#'},{'#','^','^','^','^','^','^'},{'^','^','#','^','^','#','^'},{'^','^','^','^','^','^','^'}};
	int row,col,t[50],b[50],l[50],r[50],min,count;
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
  
   /*//top n bottom
   for(int i=1;i<col;i++)
   {
   	cout<<t[i]<<b[i]<<"\n";
   }
   cout<<"\n";
   //left n right
   for(int i=1;i<row;i++)
   {
   	cout<<l[i]<<r[i]<<"\n";
   }*/
   
   
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
   	   	  	   // cout<<"Min is : "<<min<<"\n";
   	   	  	    if(min>=2)
   	   	  	    count++;
   	      }
   	   }
   }
   cases--;
   cout<<count<<"\n";
}
   
   return 0;
	
}
