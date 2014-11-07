#include<stdio.h>
#include<stdlib.h>


typedef struct node
       {
       int data;
       struct node *link;
       }node;

       void create(node *temp)
       {
          node *start;
          int i=0,t;
          printf("Terms in circular linked list?\n");
          scanf("%d",&t);
          if(t==0)
          return;
          else
          {
            start=temp;
          while(i<t)
          {
              printf("Enter the data:\n");
              scanf("%d",&(temp->data));
              fflush(stdin);
              i++;
              if(i<t)
              {
              temp->link=(node*)malloc(sizeof(node));
              temp=temp->link;
              }
           }
           temp->link=start;
          }

         }
       void display(node *temp)
       {
           node *t;
           t=temp;
           printf("\nThe Circular List Is:\n");
          do
          {
            printf("%d ",temp->data);
            temp=temp->link;
          }
          while(temp!=t);
       }
       void reverse(node *temp)
       {
        node *p,*c,*n;
        node *t;
        for(t=temp;t->link!=temp;(t=t->link)&&(p=t));
        c=temp;
        n=c->link;
        do
        {
           c->link=p;
           p=c;
           c=n;
           n=n->link;
        }
        while(c!=temp);

       }
         main()
         {
             node *list;
             list=(node*)malloc(sizeof(node));
             create(list);
             printf("Initially:\n");
             display(list);
             reverse(list);
             printf("\nAfter Reversal:\n");
             display(list);
         }

