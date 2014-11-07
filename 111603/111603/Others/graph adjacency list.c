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
    int count;//count = total no of nodes
    struct node *link;
}start;

       void create(start **st)
       {
           start *tt;
           *st=(start*)malloc(sizeof(node));
           tt=*st;
           int counter=0;
        char c;
        node *t;
        t=(node*)malloc(sizeof(node));
        printf("Enter the node data..\n",tt->data);
        scanf("%d",&(tt->data));
        fflush(stdin);
        printf("Connected to other node?");
        scanf("%c",&c);
        if(c=='y')
        {
            tt->link=t;
        while(c=='y')
       {
       printf("Enter the Connected Node : ");
         scanf("%d",&(t->data));
         counter++;
         fflush(stdin);
         printf("Connected to more nodes???\n");
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
       printf(" count is %d \n",tt->count);
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
           printf("\nThe number of nodes onnected to this node are : %d\n",temp->count);

       }
       void max_min(start *t[],int n)
       {
           printf("Starting to Find Max and Min\n");
           int i=0;
           int min,max,node_id,node_id1;
           max=t[0]->count;
           min=t[0]->count;
           printf("Count is %d",t[0]->count);
           while(i<n)
           {
               if(max<t[i]->count)
               {
                   max=t[i]->count;
                   node_id=t[i]->data;
               }
               if(min>t[i]->count)
               {
                   min=t[i]->count;
                   node_id1=t[i]->data;
               }
               i++;
            }
            printf("The node %d has the maximum nodes : %d\n",node_id,max);
            printf("The node %d has the minimum nodes : %d\n",node_id1,min);

       }

       main()
       {
       int n,i;

           printf("Enter the number of nodes in the graph :\n");
           scanf("%d",&n);
           start *s[n];
           //create(&s);
           //t=s;
           for(i=0;i<n;i++)
           {
           create(&(s[i]));
           }
          // display(s);

           for(i=0;i<n;i++)
           {
           display(s[i]);

           }

           //s=t;
           //display(s);
           max_min(s,n);

       }

