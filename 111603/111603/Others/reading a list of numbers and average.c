#include<stdio.h>
#include<conio.h>
main()
{
      int *p,i,n,sum=0;
      float avg;
      printf("enter the number of terms in the list ");
      scanf("%d",&n);
      p=(int*)malloc(n*sizeof(int));
      if(p==NULL)
      {
      printf("Soory try again... Memory not allocated...");
      }
      else{
      printf("Enter the list of numbers :");
      for(i=0;i<n;i++)
      {
      scanf("%d",p+i);
      sum=sum+*(p+i);
      }
      avg=(sum/n);
      printf("The Average of numbers is %f",avg);
      }
      getch();
      }
