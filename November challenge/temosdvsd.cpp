#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;


int main()
{
	unsigned long long a,b,i;
	double x;
	int cases,count;
	FILE *fp;
	//cin>>cases;
	//while(cases--)
	fp = fopen("ans.txt","w");
	{
		cin>>a>>b;
		count=0;
		
		for(i=0;i*i<a;i++);
		if((i+1)*(i+1)==a)
		{
			i++;
		}
		
		while( i*i <= b)
		{
			unsigned long long i_temp =i*i;
				while(i_temp!=0)
				{
					int k = i_temp%10;
					if(k==0 || k==1 || k==4 || k==9)
					{
						i_temp=i_temp/10;
						continue;
					}
					else
					{
						break;
					}
				}
				if(i_temp==0)
				{
					count++;
					fprintf(fp,"%ld,",i);
				}
				i++;
		}
		cout<<count<<endl;
	}
	fclose(fp);
	return 0;
}
