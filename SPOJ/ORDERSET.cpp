#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;



class BIT{
	int bitSize;
	vector<unsigned int> bitArray;
	public :
	BIT(int n)
	{
		bitSize =n+1;
		bitArray.resize(bitSize);
		for(int i=0;i<bitSize;i++)
		bitArray[i]=0;
	}
	void update(long long idx,long long val)
	{
		if(bitArray[idx] && val >0)
		return;
		
		if(bitArray[idx]==0 && val<0)
		return;
		//cout<<"ind : "<<idx<<endl;
		while(idx < bitSize && idx >0)
		{
		//	cout<<"up";
			bitArray[idx]+=val;
			idx += (idx)&(-idx);
		}
		display();
	}
	
	void display()
	{
		for(long long i=1;i<bitSize;i++)
		cout<<bitArray[i]<<" ";
		cout<<endl;
	}
	
	// QUERY
	long long query(long long idx)
	{
	//	cout<<"Query for "<<idx<<endl;
		long long q = 0;
		while(idx > 0 && idx < bitSize)
		{
	//		cout<<"A index : "<<idx<<endl;
			q+=bitArray[idx];
			idx -= (idx)&(-idx);
		}
	//	cout<<"Ret "<<q<<endl;
		return q;
	}
};

vector<pair<char,long long> >quer;
map<long long,int> ind_for;
vector<int> v;
int main()
{
	long long q,_q,x;
	char op;
	scanf("%lld",&q);
	//cout<<q<<endl;
	long long i=0;
	_q=q;
	int ind = 1;
	while(_q--)
	{
		fflush(stdin);
		scanf("%c",&op);
		scanf("%lld",&x);
		//cout<<op<<" "<<x<<endl;
		if(op=='I')
		ind_for.insert(make_pair(x,ind++))
	}
	
	BIT b(index.size());
	
	for(auto i=ind_for.begin();i!=ind_for.end();i++)
	v.push_back(i->first);
	
	
	for(int i=0;i<quer.size();i++)
	{
		//cout<<quer[i].first<<" "<<quer[i].second<<endl;
		switch (quer[i].first)
		{
			case 'I' :
			b.update(ind_for[quer[i].second],1);
			break;
			
			case 'D' :
			b.update(ind_for[quer[i].second],-1);
			
			break;
			
			case 'S' :
			int x = (b.query(ind_for[quer[i].second]-1));
			if(x!=0)
			printf("%lld\n",x);
			else
			printf("invalid\n");
			break;
			case 'K' :
			
			break;
			
 		}
	}
	
	return 0;
}


