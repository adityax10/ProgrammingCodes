#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a,i=0,t=0,n,j=0,count=0,*max,MAX=0,MAX_i,k=0,l=0,caught=1,prev_max,*ans;

  scanf("%d",&t);
  ans=(int*)malloc(t*sizeof(int));
  fflush(stdin);
  while(i<t)
  {
		MAX=0;
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		max=(int*)malloc(n*sizeof(int));

		for(j=0;j<n;j++)
		{
			scanf("%d",a+j);
		}

		for(j=0;j<n;j++)
		{

			for(k=j+1;k<n;k++)
			{
				if(*(a+j)<(*(a+k)))
				count++;

			}
		//	printf("Count a %d = %d\n",j,count);
			*(max+j)=count;
			count=0;
		}


 	for(j=0;j<n;j++)
 {
        MAX=*(max+j);
	  // printf("Initaillay  MAX %d\n",MAX);
		for(l=j+1;l<n;l++)
		{
			if(MAX<*(max+l))
			 {MAX=*(max+l);
             j=l;
			 //printf("new  MAX %d\n",MAX);
			 }
		}
		if((MAX>0)&&(prev_max!=MAX))
		{caught++;
	//	printf("caught= %d\n",caught);
	    //	MAX=0;
	}
		prev_max=MAX;
	}
    *(ans+i)=caught;
	caught=1;
	i++;
  }

  for(i=0;i<t;i++)
  {
		printf("%d\n",*(ans+i));
  }
  getch();
}
