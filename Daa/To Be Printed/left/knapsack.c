#include<stdio.h>
#include<conio.h>

int main()
{
    float *temp,*res,t,profit=0;
    int n,cap,*p,*w,remwt=0,i,*y,j;
    printf("enter number of weights to be entered: ");
    scanf("%d",&n);
    printf("enter capacity of sack: ");
    scanf("%d",&cap);
    remwt=cap;
    res=(float *)malloc(n*sizeof(float));
    if(res==NULL)
    {
               printf("enough memory not available");
               exit(0);
    }
    y=(int *)malloc(n*sizeof(int));
    if(y==NULL)
    {
               printf("enough memory not available");
               exit(0);
    }
    p=(int *)malloc(n*sizeof(int));
    if(p==NULL)
    {
               printf("enough memory not available");
               exit(0);
    }
    w=(int *)malloc(n*sizeof(int));
    if(w==NULL)
    {
               printf("enough memory not available");
               exit(0);
    }
    temp=(float *)malloc(n*sizeof(float));
    if(temp==NULL)
    {
               printf("enough memory not available");
               exit(0);
    }
    printf("enter %d weights and their corresponding profits: \n",n);
    for(i=0;i<n;i++)
    {
                    scanf("%d %d",&w[i],&p[i]);
                    temp[i]=(((float)p[i])/w[i]);
                    res[i]=0; 
    }
    for(i=0;i<n;i++)
    {
                    t=0;
                    y[i]=i;
                    for(j=0;j<n;j++)
                    {
                                      if(temp[j]>t)
                                      {
                                                   y[i]=j;
                                                   t=temp[j];
                                      }
                    }
                    temp[y[i]]=0;
    }        
    i=0;
    while(i<n)
    {
              if(remwt>=w[y[i]])
              {
                                res[y[i]]=1;
                                remwt=remwt-w[y[i]];
                                profit+=p[y[i]];
                                i++;
              }
              else
                  break;
    }
    if(i<n)
    {
           res[y[i]]=(((float)remwt)/w[y[i]]);
           profit+=((res[y[i]])*(p[y[i]]));
    }
    printf("fraction of all weights in sack: \n");
    for(i=0;i<n;i++)
                    printf("%d --> %f\n",w[i],res[i]);
    printf("\nTotal profit: %f",profit);
    getch();
    return 0;
}
