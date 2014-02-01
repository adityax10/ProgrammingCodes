#include<iostream>

using namespace std;

int a[1000001];
int a_seg[1000001];


int main()
{
	unsigned long long l,r,k,seg_index,count=0;
			 //SIEVE
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
	
	cin>>l>>r;
	// seg seive
/*	for(unsigned long long j=2; j<=1000000;j++)
	{
		if(!a[j])
	{
				k=l;
			while(k%j != 0)
			{
				k++;
			}
			while(k<=r)
			{
				seg_index = k%1000000;
				if(seg_index == 0 && k==r)
				seg_index = 1000000;
				a_seg[seg_index]=1;
			
				k+=j;
			}}
	}  
	*/
	
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
			//cout<<"ADI : k= "<<k<<-" pn = "<<j<<endl;
		//	prev_num = j;
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
	

	
	for(k=l;k<=r;k++)
	{
		if(a_seg[k%1000000]==0)
		{
			count++;
		//	cout<<k<<endl;
		}
	}
	cout<<count<<endl;
	
}
