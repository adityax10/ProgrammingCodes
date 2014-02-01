#include<iostream>

using namespace std;

void main()
{
 unsigned long long a[100];
 int i,j,k,count=0;
 
cin>>i;
	 for(j=0;j<i;j++)
	 {
	    cin>>a[j];
	 }
	 cin>>k;
	 
	for(j=0;j<i;j++)
	{
		cout<<j<<" "<<a[j]<<"\n";
	    if(a[j] < a[k-1])
	    {
	     count++;
	    }
	}  
    printf("%d",count+1);
}

