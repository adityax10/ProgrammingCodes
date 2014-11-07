#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h> 
#define TRUE 1 
#define FALSE 0 

typedef struct job 
{     
        int profit;     
        int deadline; 
}job;
 
int main() 
{     
      int n,i,q,k,r,*j,lastprofit=INT_MAX,profit=0;     
      int *d,*p;     
      printf("Enter the number of jobs : "); 
      scanf("%d",&n);         
      j=(int *)malloc((n+1)*sizeof(int));     
      p=(int *)malloc((n+1)*sizeof(int));     
      d=(int *)malloc((n+1)*sizeof(int));     
      if((j==NULL)||(p==NULL)||(d==NULL))     
      {         
                printf("enough memory not available...");         
                exit(0);     
      }   
      printf("Enter profit and deadline for %d jobs in descending order of profits: \n",n);     
      for(i=1;i<=n;i++)     
      {         
                scanf("%d %d",p+i,d+i);         
                if(p[i]>lastprofit)         
                {             
                              printf("error...profits are not in descending order...");             
                              exit(0);         
                }         
                lastprofit=p[i];    
      }
      d[0]=j[0]=0;     
      j[1]=1;     
      k=1;     
      profit=p[1];     
      for(i=2;i<=n;i++)     
      {         
	        r=k; 
	        while((d[j[r]]>d[i])&&(d[j[r]]!=r))
	                                           r--;         
	        if((d[j[r]]<=d[i])&&(d[i]>r))         
	        {             
	                      for(q=k;q>=r+1;q--)
	                                         j[q+1]=j[q];             
	                      j[r+1]=i;             
	                      profit=profit+p[i];             
	                      k++;         
	        }     
      }     
      printf("The maximum profit is: %d\n",profit);     
      printf("The schedule is: \n");     
      for(i=1;i<=k;i++)
                       printf("%d\t",j[i]); 
      getch();
      return 0;
}
