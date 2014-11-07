#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

struct node
{
	int m,f;
};

node  nd[100];
int co =0;
inline int fx(const void *a,const void *b)
{
	node *x = (node * )a;
	node *y = (node *)b;
	if(x->f < y->f)
	{
		co++;
		return -1;
	}
	return 1;
}

int main()
{	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>nd[i].m >>nd[i].f;
	}
	
	qsort(nd,n,sizeof(node),fx);
	cout<<co;

	return 0;
}


