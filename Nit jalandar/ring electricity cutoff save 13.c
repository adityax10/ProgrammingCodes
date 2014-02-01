#include<stdio.h>
#include<stdlib.h>

int save_13(int a[],int n,int x)
{
    int count=0,i=1,k;
    a[0]=0;


    while(1)
    {
        for(;;i++)
        {
        if(count>n)
        count=count%n;

        if(count==x)
        {
            a[i]=0;
        count=0;
        }
        if(a[i]!=0)
        {
        x=a[i];
        a[i]=0;
        count++;
        }
        }


    }




}

int main()
{
  int a[100],i,x=0,n;

  scanf("%d",&n);

  for(i=0;i<n;i++)
  a[i]=++i;


  for(i=n;i>=0;i++)
  {
      if(x=1)
      break;
      else
      x=save_13(a,n,i);
  }

}
