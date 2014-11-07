#include<bits/stdc++.h>
using namespace std;

int cal_kth_element(int a[],int b[],int n,int m,int k)
{
	int a_l=0,a_r=n;
	int b_l=0,b_r=m;
	
	while( a_l>=0 && a_l <=n && b_l >=0 && b_l <=m && a_r>=0 && a_r<=n && b_r>=0 && b_r <=n && a_l<=a_r && b_l<=b_r)
	{
		//int x;
		//cin>>x;
		int a_mid = (a_l+a_r)/2;
		int b_mid = (b_l+b_r)/2;
		cout<<"A ["<<a_l<<" ... "<<a_r<<"]"<<endl;
		cout<<"B ["<<b_l<<" ... "<<b_r<<"]"<<endl;
		cout<<endl;
	
		// now eliminating the array parts
		// if a[a_mid] > b[b_mid]...
		if(a[a_mid] > b[b_mid])
		{
			// if sum is less... eliminate the larger array
			if(k < a_mid + b_mid + 2)
			{
				a_r = a_mid-1;
			}
			else // eliminate the smaller array
			{
				b_l = b_mid+1;				
			}
		}
		else
		{
			// if sum is less... 
			if(k < a_mid + b_mid+2)
			{
				b_r = b_mid-1;
			}
			else
			{
				a_l = a_mid+1;				
			}
		}
	}
	cout<<"A ["<<a_l<<" ... "<<a_r<<"]"<<endl;
	cout<<"B ["<<b_l<<" ... "<<b_r<<"]"<<endl;
	
	if(a_l > a_r)
	return b[k-a_l-1];
	else
	return a[k-b_l-1];
	
}

int main()
{
	int a[] = {1,3,5,9,11,13,17}; //n
	int b[] = {2,4,10,16,20}; //m
	//int a[]={1,2,5,6};
	//int b[]={3,4,7,8};
	int k = 12; // 0<=k<= n+m;
	cout<<cal_kth_element(a,b,sizeof(a)/sizeof(int) -1,sizeof(b)/sizeof(int) -1 ,k);
	return 0;
}


