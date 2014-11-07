#include<iostream>
#include<math.h>

using namespace std;

int a[1000001];
int a_seg[1000001];

unsigned long long find_divs(unsigned long long x)
{
	unsigned long long i=2,i_temp,count=0,q=1;
	int flag=0;
	
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
			   // cout<<"After , x= "<<x<<" count " <<count<<" i = "<<i<<" i_temp = "<<i_temp<<endl;
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
	unsigned long long l,r,ans,count,seg_index,k;
	int cases;
	
		 //SIEVE => 0 to 10^6
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
	cin>>cases;
	while(cases--)
	{
		cin>>l>>r;
		// Segmented_Sieve a_seg l=> r; using sieve 0 => 10^6
			if(r>1000000)
			{
			    //initailing a_seg[]
				for(k=0;k<=1000000;k++)
				a_seg[k]=0;
				unsigned long long prev_num=1;
				for(unsigned long long j =2;j*j<=r;j++)
				{
					if(!a[j])
					{
						if(l%j==0)
						{
							k=l;
						}
						else
						/*k=(l/j) *j + j*prev_num;
						if(k<l)*/
						k=(l/j)*j+j;
						//cout<<"ADI : k= "<<k<<" pn = "<<j<<endl;
						prev_num = j;
						while(k<=r)
						{
							seg_index = k%1000000;
							if(seg_index == 0 && k==r)
							seg_index = 1000000;
							//cout<<"Removing "<<k<<" at "<<seg_index<<endl;
							a_seg[seg_index]=1;
							k+=j;
						}
					}
				}
				
			}
		
		count=0;
		if(l==1)
		l++;
		
		for(unsigned long long i=l;i<=r;i++)
		{
			if(i <= 1000000 && a[i]==0)//ie i is  prime it will have 2 factors..
			{
				count++;
				continue;
			}
			
			seg_index = i%1000000;
			if(seg_index==0 && i==r )
			seg_index = 1000000;
			
		    if(i>1000000 && a_seg[seg_index]==0)
		    {
		    	count++;
		    	continue;
		    }
		    //otherwise
			ans = find_divs(i);
			 if( ans!=0  && a[ans+1]==0 )
			 { 
		    	count++;
		     } 
		}
		cout<<count<<"\n";
	} 
	return 0;
}
