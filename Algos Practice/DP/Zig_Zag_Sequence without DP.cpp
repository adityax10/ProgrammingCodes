#include<iostream>

using namespace std;

int find_len(int a[],int n)
{
	bool bin[n];
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
			bin[i]=1;
		else if(a[i]<a[i-1])
	        bin[i]=0;
	    else
	    bin[i]=bin[i-1];
	}
	int count=2;
	for(int i=2;i<n;i++)
	{
		if(bin[i] == !bin[i-1])
		{
			count++;
		//	cout<<"i= "<<a[i]<<" c "<<count<<endl;
		}
	}
	return count;
}

int main()
{
	int a[]={{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	cout<<find_len(a,sizeof(a)/sizeof(int));
	return 0;
}


