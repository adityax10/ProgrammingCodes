#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

inline int fx(const void *a,const void *b)
{
	cout<<"C :"<<*(int*)a<<" "<<*(int*)b<<endl;
return -( *(int*)a - *(int*)b );
}
int main()
{
	int a[] = {1,2,3,4,5};
	qsort(a,5,sizeof(int),fx);
	for(int i=0;i<5;i++)
	cout<<a[i];
	return 0;
}


