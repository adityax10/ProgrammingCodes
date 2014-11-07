#include<stdio.h>
#include<math.h>

int main()
{
	int i,j,c=0,k,l,count;
	long int a,b;
	
	while(1)
	{
	scanf("%ld %ld",&a,&b);
	count=0;
	if(a==1)
	a++;
	for(i=a;i<=b;i++)
	{
		c=0;
		//printf("Checking for i = %d\n",i);
		for(j=2;j<=(i)/2;j++)
		{
			//printf("Dividing by %d\n",j);
			if(i%j==0)
			{
			c++;
			break;}
		}
		if(c)
		continue;
		//printf("p %d\n",i);
		if(c==0)
		{
			/*for(k=1;k<(float)sqrt(i);k++)
			{
				int temp = i-pow(k,2);
				if(temp <= 0)
				continue;
				if((float)sqrt(temp)-(int)temp==0)
				{
				count++;
				break;
			    }
			}*/
			if(i%4==1||i==2)
			{
				count++;
			}
			
			
		}
	}
	printf("%d\n",count);
	count=0;
}

}
