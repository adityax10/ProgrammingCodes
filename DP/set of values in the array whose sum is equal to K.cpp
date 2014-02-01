#include<iostream>

using namespace std;

void print_arr(int a[])
{
	for(int i=7;i>=0;i--)
	if(a[i]!=NULL)
	cout<<a[i];
	cout<<endl;
}

int find_sets(int arr[],int i,int sum)
{
	//cout<<"i= "<<i<<"Sum = "<<sum<<"\n";
	
	if(sum<0 || i<0)
	return 0;
	
	if(sum==0)
	{
	//	print_arr(set);
	    return 1;
    }
	
	//set[i-1]=arr[i-1];
	int x = find_sets(arr,i-1,sum-arr[i-1]);
	//set[i-1]=NULL;
	int y = find_sets(arr,i-1,sum);
	return x+y;
}

int main()
{
	int arr[8]={15,6,5,7,8,9,1,8};
	int sum=15,i;
	
	cout<<find_sets(arr,8,sum);
	
}
