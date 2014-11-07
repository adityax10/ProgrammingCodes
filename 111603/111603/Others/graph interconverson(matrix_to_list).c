#include<stdio.h>

#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;

typedef struct start
{
    int data;
    int count;
    node *link;
}start;

create_matrix(int **a,int n)
{
    int i,j;
    char c;
    printf("Enter the Graph!\n");
    for(i=0;i<n;i++)
           {
            printf("For node %d:\n",i);
           for(j=0;j<n;j++)
           {
               if(i!=j)
               {
               *(a+n*i+j)=0;
               printf("Connected to %d ?\n",j);
               fflush(stdin);
               scanf("%c",&c);
               fflush(stdin);
               if(c=='y')
              *(a+n*i+j)=1;
               }
           }
          }}

          display_matrix(int **a,int n)
          {
              int i,j;
               printf("Adjacency matrix is...\n");
           for(i=0;i<n;i++)
           {
           for(j=0;j<n;j++)
           {
               if(i==j)
               printf("X ");
               //if(j>i)
               else
               printf("%d ",*(a+n*i+j));

               //else
               //printf("X ");
           }
           printf("\n");
          }
          }

          convert_matrix_to_list(int **a,int n)
          {
              int i,j;
              int counter=0;
              node *t;
              start *s[n];
              printf("Converting..\n");
              printf("Initially s[0]->data=%d\n",(s[0])->data);


              for(i=0;i<n;i++)
              {
                  (s[i])->data=i;
                  printf("Assigned s[%d]->data=%d\n",i,s[i]->data);
                  t=s[i]->link;
                  for(j=0;j<n;j++)
                  {
                      if((*(a+n*i+j)==1)&&(i!=j))
                         {
                             t->data=j;
                             counter++;
                             t->link=(node*)malloc(sizeof(node));
                             if(j<n-1)
                             t=t->link;
                             else
                             t->link=NULL;
                         }

                  }
                  s[i]->count=counter;
                  counter=0;


              }
          }



main()
{
   int n,i,j;
   char c;

           printf("Enter the number of nodes in the Graph :\n");
           scanf("%d",&n);
           int a[n][n];
           create_matrix(a,n);
           display_matrix(a,n);
           convert_matrix_to_list(a,n);
           }


