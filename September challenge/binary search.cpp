#include<iostream>
#include<map>
using namespace std;

int a[]={5,7,9,15,20};

int main()
{
	map<int,bool> x;
	for(int i=0;i<5;i++)
		x[a[i]]=true;
	while(1)
	{
	
	int n;
	cin>>n;
	auto i=x.find(n);
	if(i!=x.end())
	{
			cout<<i->first;
	}
	else
	{
		x[n]=false;
		auto j=x.find(n);
		j++;
		cout<<j->first;
		x.erase(n);
	}
    }
}
