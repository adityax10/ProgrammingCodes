#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

set<long long int> s;

int main()
{
	int q,x;
	char op;
	scanf("%d",&q);
	while(q--)
	{
		fflush(stdin);
		scanf("%c",&op);
		scanf("%d",&x);
		switch(op)
		{
			case 'I' :
				s.insert(x);
				break;
			case 'D' :
				s.erase(x);
				break;
			case 'C' :
				printf("%d\n",90);
				break;
			case 'K' :
				printf("%d",*(next(s.begin(),x)));
				break;
		}
	}
		

	return 0;
}

