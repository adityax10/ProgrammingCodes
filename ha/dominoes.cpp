#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
	int num,i,count=0,x;

	scanf("%d",num);
	x=sqrt(num)+1;

	if(num<3)
	printf("1");
	else
{

	for(i=2;i<=x;i++)
	{
		if(num%i!=0)
		count++;
		else
		break;
	}
	if(count!=x-1)
	printf("2");
	else
	printf("1");
}
return 0;

}
