#include<bits/stdc++.h>
using namespace std;

//O(n)
int majority_index(int a[],int n)
{
	//choose 0 at begining
	int max_freq_ind = 0;
	int c=0;
	for(int i=0;i<n;i++)
	{
		// if more elements are found 
		if(a[max_freq_ind]==a[i])
		c++;
		// if not found
		else
		c--;
		
		if(c < 0)
		{
			max_freq_ind=i;
			c=0;
		}
		//cout<<a[max_freq_ind]<<endl;
	}
	//check to veriify thart we have the element with freq >= n/2
	c=0;
	for(int i=0;i<n;i++)
	{
		if(a[max_freq_ind]==a[i])
		c++;
	}
	if(c<=n/2)
	{
	cout<<"Doesn't exixst";
	return -1;
	}
	else
	cout<<a[max_freq_ind]<<endl;
}

int main()
{
	int a[]={1,2,2,2,3,4,5,2,2};
	
	majority_index(a,sizeof(a)/sizeof(int));

	return 0;
}


