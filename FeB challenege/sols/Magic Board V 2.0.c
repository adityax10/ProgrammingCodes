#include<stdio.h>
#include<stdlib.h>

int main()
{
int *row,*col,n,m,x,r,c,i;

    printf("Enter the size of the Board : \nRows :");
    scanf("%d",&n);
    printf("Columns :");
    scanf("%d",&m);

    row=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    *(row+i)=0;
    col=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    *(col+i)=0;


    while(i!=-1)
    {

    printf("Enter the choice : \n1. RowSet i a\n2. ColumnSet i a\n3. RowQuery i \n4. ColQuery i \n5. Display \n6. Exit\n");
    printf("Choice : "); scanf("%d",&i);
    switch(i)
    {
        case 1: printf("Enter the row no > ");
                scanf("%d",&r);
                printf("Value to be assigned :");
                scanf("%d",&x);
                rowset(row,col,r,x,m,n);
                break;

        case 2: printf("Enter the col no > ");
                scanf("%d",&c);
                printf("Value to be assigned :");
                scanf("%d",&x);
                colset(row,col,c,x,m,n);
                break;

       case 3: printf("Enter the row no > ");
                scanf("%d",&r);
                rowquery(row,r);
                break;
        case 4: printf("Enter the col no > ");
                scanf("%d",&c);
                colquery(col,c);
                break;

       case 5 : display(row,m);
                display(col,n);
                 break;

       case 6 : i=-1;
                break;

      default : printf(" \n !! Enter a valid option !!\n");



    }
    }
}

void rowset(int *row,int *col,int r,int x,int m,int n)
{
    int i;
    if(x==1)
    {
        if(*(row+r-1)<m)
        {
        *(row+r-1)=m;
        for(i=0;i<n;i++)
        {
         if(*(col+i)<n)
         (*(col+i))++;
        }
    }}
    else if(x==0)
    {
        *(row+(r-1))=0;
        for(i=0;i<n;i++)
        if(*(col+i))
        (*(col+i))--;
    }

    else
    printf("\n Enter ONLY 1 or 0 !!\n");
}

void colset(int *row,int *col,int c,int x,int m,int n)
{
    int i;
    if(x==1)
    {
        if(*(col+c-1)<n)
        {
        *(col+(c-1))=n;
        for(i=0;i<m;i++)
        {
         if(*(row+i)<m)
         (*(row+i))++;
        }
    }}
    else if(x==0)
    {
        *(col+(c-1))=0;
        for(i=0;i<m;i++)
        if(*(row+i))//*(row+i)!=0
        (*(row+i))--;
    }

    else
    printf("\n Enter ONLY 1 or 0 !!\n");
}

void rowquery(int *a,int r)
  {
      printf("\nOnes in %d row: %d \n",r,*(a+(r-1)));
  }

  void colquery(int *a,int r)
  {
      printf("\nOnes in %d col: %d \n",r,*(a+(r-1)));
  }

void display(int *a,int n)
{
   int i;
   for(i=0;i<n;i++)
   printf("%3d ",*(a+i));
   printf("\n");
}
