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
    struct node *link;
}start;

 void create_list(start **st)
       {
           start *tt;
           *st=(start*)malloc(sizeof(node));
           tt=*st;
           int counter=0;
        char c;
        node *t;
        t=(node*)malloc(sizeof(node));
        printf("Enter the node ..\n",tt->data);
        scanf("%d",&(tt->data));
        fflush(stdin);
        printf("Connected to other node?");
        scanf("%c",&c);
        if(c=='y')
        {
            tt->link=t;

        while(c=='y')
       {
       printf("Enter :");
         scanf("%d",&(t->data));
         counter++;
         fflush(stdin);
         printf("connected to more nodes???\n");
        scanf("%c",&c);
        if(c=='y')
           {
            t->link=(node*)malloc(sizeof(node));
            t=t->link;}
        else
            t->link=NULL;
       }}
       else
       {
           tt->link=NULL;
       }
       tt->count=counter;
       printf(" count is %d\n",tt->count);
       }


convert_list_to_matrix(start *s[],int n)
{
    printf("Entered in convert...\n");
  int i,j;
  int a[n][n];
  node *t;
  //t=s->link;
  //printf("values allocated...\n");

  for(i=0;i<n;i++)
  {
      t=s[i]->link;
      for(j=i+1;j<n;j++)
      {
          a[i][j]=0;
    if(t!=NULL)
          {
   if(j=t->data)
   {
   a[i][j]=1;
   printf("Assigned 1 at a[%d][%d]\n",i,j);
  }
  t=t->link;
  }}
}
 for(i=0;i<n;i++)
           {
               for(j=0;j<n;j++)
               {
                   if(j>i)
                   printf("%d ",a[i][j]);
                   else
                   printf("X ");
               }
               printf("\n");
           }
}

void display(start *temp)
       {
           node *p;
           p=temp->link;
           printf("The node %d is connected to....\n",temp->data);
           while(p!=NULL)
           {
               printf("%d  ",p->data);
               p=p->link;
           }
           printf("\nThe nodes onnected to this node are : %d\n",temp->count);


}
main()
{
   int n,i;

           printf("Enter the number of nodes in the graph :\n");
           scanf("%d",&n);
           start *s[n];
           int a[n][n];

           for(i=0;i<n;i++)
           {
           create_list(&(s[i]));
           };


           for(i=0;i<n;i++)
           {
           display(s[i]);

           }



           convert_list_to_matrix((s),n);




}

