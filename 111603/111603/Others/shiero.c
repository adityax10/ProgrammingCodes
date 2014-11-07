#include<stdio.h>
#include<conio.h>

//float stored_shiero[100][100];
int sum_a;
float shiero(int a[],int p[],int k,int i,int n)
{
    float q;
 //	printf("k =%d i = %d n =%d \n",k,i,n);
 	if(k>=sum_a-k)
 	{
	// printf("Returned 1\n");
	 		return 1;
 	}
 	else if(k<sum_a-k && i > n)
 	{
	 				//printf("Returned 0\n");
	 		  return 0;
	 		  
 	}
 	//if(stored_shiero[n]!=-1)
 	//return stored_shiero[n];
 	//stored_shiero[n]=-1;
 	q = (((float)(p[i])/100)*(float)shiero(a,p,k+a[i],i+1,n)+((float)(100-p[i])/100)*(float)shiero(a,p,k,i+1,n));
 //	printf("shiero(%d) is %f\n",i,q);
 	return q;
 	//stored_shiero[n] = i;
 	
 	
}


int main()
{
 	int a[100],p[100],n,i,cases;
 	
 	scanf("%d",&cases);
 	while(cases>0)
 	{
    sum_a=0;
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
	 		scanf("%d",&a[i]);
 	}
 	for(i=1;i<=n;i++)
 	{
	 				scanf("%d",&p[i]);
 	}
 	for(i=1;i<=n;i++)
 	{
	  sum_a = sum_a+a[i];
	 // product_a = product_a*a[i];
 //	stored_shiero[i]=-1;
    }
 	printf("%f\n",(float)shiero(a,p,0,1,n));
 	cases--;
    }
    return 0;
}
