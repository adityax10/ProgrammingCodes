#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



int parent[100],size[100];

int find(int i)
{
	while(parent[i]!=i)
	i=parent[i];
	return i;
}
void Union(int i,int j)
{
	int p1=find(i);
	int p2=find(j);
	if(p1==p2)
	return;
	if(size[p1]<size[p2])
	swap(p1,p2);
	parent[p2]=p1;
	size[p1]+=size[p2];
}

int main()
{
	int n,count=0;
	cout<<"Elements ? : ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	parent[i]=i;
	size[i]=1;
    }
    
    Union(1,2);
    Union(3,2);
    for(int i=1;i<=n;i++)
    {
    	if(parent[i]==i)
    	count++;
    }
    cout<<count<<endl;
	return 0;
}


