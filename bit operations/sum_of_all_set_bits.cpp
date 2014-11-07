#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,cases;
	int count;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		count =0;
		for(int i=1;i<=n;i++)
		{
			int num = i;
			while(num)
			{
				if(num&1)
				count++;
				num= num>>1;
			}
		}
		printf("%d\n",count);
    }
	return 0;
}


