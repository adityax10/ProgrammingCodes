#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

struct flower{
	int h,l,w;
};

flower f[100];

inline int func(const void *f1,const void *f2) 
{
	flower a = *(flower*)f1;
	flower b = *(flower*)f2;
	cout<<"Comparing : "<<a.h<<" "<<b.h<<endl;
	if((a.l < b.l && a.w < b.l )|| (a.l > b.w && a.w > b.w))
	{
		cout<<"C1\n";
		if(a.h > b.h)
		return -1;
		else
		return 1;
	}
	else if(a.l == b.l && a.w == b.w)
	{
		cout<<"C2\n";
		if(a.h > b.h)
		return 1;
		else
		return -1;
	}
	else
	{
		cout<<"C3\n";
		if(a.h > b.h)
		return 1;
		else
		return -1;
	}
}

void sort(int l,int r,int n)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		sort(l,mid,n);
		sort(mid+1,r,n);
		merge(l,r);
	}
}

void merge(int l,int r)
{
    int mid;
    mid=(l+r)/2;
    int abc[30],i=l,j=mid+1,k=l;
    printf("Sorting A[%d] between A[%d] \n",l,r);

    while((i<=mid)&&(j<=r))
    {
    if(func())
    {
        abc[k]=list[j];
        j++;k++;
    }
    else if(list[i]<list[j])
    {
        abc[k]=list[i];
        i++;k++;
    }
    }
    
    if(i>mid)
    {
        while(j<=r)
        {
        abc[k]=list[j];
        k++;j++;
        }
    }
    else if(j>r)
    {
        while(i<=mid)
        {
        abc[k]=list[i];
        k++;i++;
        }
	}
    for(k=l;k<=r;k++)
    {
        list[k]=abc[k];
    }

}


int main()
{
	//int h[]={1,2,3,4,5,6}; 
	//int b[]={1,3,1,3,1,3};
	//int w[]={2,4,2,4,2,4};
	
	//int h[]={3,2,5,4};
	//int b[]={1,2,11,10};
	//int w[]={4,3,12,13};
	
	int h[] = {5,4,3,2,1};
    int b[]={1,5,10,15,20};
	int w[]={5,10,14,20,25};

	int n = sizeof(h)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		flower a;
		a.h=h[i];
		a.l=b[i];
		a.w=w[i];
		f[i]=a;
    }
    sort();
    
    for(int i=0;i<n;i++)
    cout<<f[i].h<<" ";
	
	return 0;
}


