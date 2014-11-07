#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

bool find_t(int x,int y,bool t) // 0=>1
{
	if(x==y)
	{
		if(t==0)
		{
			return 0;
		}
		else
		{
			find_t(x,y+x,!t);
			find_t(x+y,x,!t);
		}
	}
	else if(x<y)
	find_t(x,x-y,!t);
	else if(y>x)
	find_t(x-y,x,!t);
}	
int main()
{
	if(find_t(4,5,0)==0)
	{
		cout<<"Won";
	}

	return 0;
}


