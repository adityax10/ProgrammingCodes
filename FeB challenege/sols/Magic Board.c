#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a,i,n,m,r,c,x;

    printf("Enter the size of the Board : \nRows :");
    scanf("%d",&n);
    printf("Columns :");
    scanf("%d",&m);

    a=(int *)malloc(sizeof(int)*n*m);

    for(i=0;i<n*m;i++)
    *(a+i)=0;
    display(a,n,m);

    while(i!=-1)
    {

    printf("Enter the choice : \n1. RowSet i a\n2. ColumnSet i a\n3. RowQuery i \n4. ColQuery i \n5. Display \n6. Exit");
    scanf("%d",&i);
    switch(i)
    {
        case 1: printf("Enter the row no > ");
                scanf("%d",&r);
                printf("Value to be assigned :");
                scanf("%d",&x);
                rowset(a,r,x,m);
                break;

      case 2: printf("Enter the col no > ");
                scanf("%d",&c);
                printf("Value to be assigned :");
                scanf("%d",&x);
                colset(a,c,x,n);
                break;

       case 3: printf("Enter the row no > ");
                scanf("%d",&r);
                rowquery(a,r);
                break;
        case 4: printf("Enter the col no > ");
                scanf("%d",&c);
                colquery(a,c);
                break;

       case 5 : display(a,n,m);
                 break;

       case 6 : i=-1;
                break;

      default : printf("Enter a valid option !\n");
    }


    }
}

 void rowset(int *a,int r,int x,int m)
 {
     int i;
     for(i=0;i<m;i++)
     *(a+((r-1)*m)+i)=x;
 }

 void colset(int *a,int c,int x,int n)
 {
     int i;
     for(i=0;i<n;i++)
     *(a+((i*n)+c-1))=x;
 }

  void rowquery(int *a,int r,int m)
  {
      int i,count=0;
      for(i=0;i<m;i++)
      if(*(a+(r-1)*m+i)==0)
      count++;
      printf("\nZeros in row:%d \n",count);
  }

  void colquery(int *a,int c,int n)
  {
      int i,count=0;
      for(i=0;i<n;i++)
      if(*(a+(i*n)+c-1)==0)
      count++;
       printf("\nZeros in col:%d \n",count);

  }


void display(int *a,int n,int m)
{
    int i,j;
    for(i=0;i<n;i++){
    for(j=0;j<m;j++)
    printf("%d ",*(a+m*i+j));
    printf(" \n");}
}
