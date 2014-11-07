#include<stdio.h>
#include<conio.h>
main()
{
      int i,j;
      int a[40][40],b[40],c[40],n,m,l,k;
      int max=a[0][0],min=32;
      printf("Enter the order of the array");
      scanf("%d%d",&n,&m);
      printf("Enter the values of the terms of the array\n");
      for(i=0;i<n;i++)
      {
                      for(j=0;j<m;j++)
                      {
                                      scanf("%d",&a[i][j]);
                                      }
                                      }
      printf("The array entered by you is..\n");
      for(i=0;i<n;i++)
      {
                      for(j=0;j<m;j++)
                      {
                                      printf("%d\t",a[i][j]);
                                      }
                                      printf("\n");
                                      
                                      }
      for(i=0;i<n;i++)
      {
                      
                     max=a[i][0]; 
                     for(j=0;j<m;j++)
                     {
                                      if(a[i][j]>max)
                                      {
                                     max=a[i][j];
                                      l=j;
                                      b[i]=max;}}
                                      min=a[l][0];
                                      for(k=0;k<m;k++)
                                      {
                                      if(a[k][l]<=min)
                                      {
                                                     min=a[k][l];
                                                     c[i]=min ;
                                                     
                                                     }}}
      for(i=0;i<n;i++)
      {
                      if(b[i]==c[i])
      {
      printf("Saddle point is..... %d",b[i]);
      }
      }
      getch();
      }
      
      
