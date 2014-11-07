#include<iostream>
#include<math.h>
using namespace std;
int a[1000001];
unsigned long long find_divs(unsigned long long x)
{
	unsigned long long i=2,i_temp,count=0,q=1;
	
	if( (!(x%2) && !(x%3)) ||  (!(x%2) && !(x%5)) ||  (!(x%5) && !(x%3)) )
	return 0;
	
	while(i*i<=x)
	{
		if(x%i==0)
		{
			i_temp=i;
			while(x%i==0)
			{
			//	cout<<"x= "<<x<<endl;
				if(x%(i*i) == 0)
				{
					i_temp=i;
					q=q*2;
					i=i*i;
					x=x/i;
					count+= q;
				}
				else
				{
				x=x/i;
				count+= q;
			    }
			    //cout<<"After , x= "<<x<<" count " <<count<<" i = "<<i<<" i_temp = "<<i_temp<<endl;
			    while(x!=1 && x%i !=0)
			    {
			    	q=q/2;                                                            
			    	i=sqrt(i);
			    	i_temp=sqrt(i);
			    //	cout<<"decrementing i = "<<i<<" q = "<<q<<endl;
			    }
			    
			    if(i==1)
			    {
			    	break;
			    }
			   // char c;
			    //cin>>c;
			}
			if(x==1)
			{
				return count;
			}
			else
			{
				return 0;
			}
	    }
	    else
	    {
	    	i++;
	    	while(a[i]!=0)
	    	i++;
	    }
	}
	return 1;
}

int main()
{
	
	for(long long j=2;j*j<=1000000;)//for the numbers
	{
		if(a[j]==0)
		{
			long long k;
			k=j*j; 
			while(k<=1000000)//shifts for crossing
			{
				a[k]=1;
				k+=j;
			}
	    }
	    if(j==2)
	    j++;
	    else
	    j+=2;//as even nos should not be considered
	}
	
	for(unsigned long long j=1;j<=1000000;j++)
	cout<<find_divs(j);
}
