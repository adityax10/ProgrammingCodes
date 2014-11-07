#include<iostrea>

using namespace std;

int main()
{
	int x,cases,n,sum1,sum2;
	
	cin>>cases;
	while(cases)
	{
		cin>>n;
		sum1=0;
		sum2=0
		for(int i=0;i<n;i++)
		{
			cin<<x;
			sum1=sum1+x;
		}
		for(int i=0;i<n;i++)
		{
			cin<<x;
			sum2=sum2+x;
		}
		if(sum2 < sum1)
		{
			cout<<"-1\n";
		}
		else if(sum1==sum2)
		{
			
		}
		else
		{
			cout<<(sum1-sum2)<<"\n";
		}
		cases--;
   }
   return 0;
}
