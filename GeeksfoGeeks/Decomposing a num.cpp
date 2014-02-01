#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int ans[1000];
int flag[1000];

void decompose(int num,int ans_size)
{
	if(num>0 )
	{
		cout<<num<<" ";
		for(int i=0;i<ans_size;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
		for(int i=1;i<=num;i++)
		{
			ans[ans_size]=i;
			decompose(num-i,ans_size+1);
		}
	}
	return ;
}
	
int main()
{
	decompose(5,0);
	return 0;
}


