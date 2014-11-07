#include<stdio.h>


int main()
{
	int n,i=0,x[3][10000],temp,l=0,count=0,z=0,j=0,q;

	scanf("%d",&n);

	for(j=0;j<n;j++)
	{
		x[j][0]=0;
		scanf("%d %d",&x[j][1],&x[j][2]);
	}


	scanf("%d",&q);
	i=0;
    while(i<q)
	{
		scanf("%d",&j);
		for(z=0;z<j;z++)
		{
			scanf("%d",&temp);
			fflush(stdin);
			for(l=0;l<n;l++)
			{
			    printf("x[l][0] =  %d ",x[l][0]);
				if(x[l][0]==0)
				{
				if((temp>=x[l][1])&&(temp<=x[l][2]))
				{
				count++;
				x[l][0]=-1;
			    }
			    }
		    }}
  printf("%d",count);
  i++;
  count=0;
  for(l=0;l<n;l++)
  x[l][0]=0;
	}

return 0;

}
