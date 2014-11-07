#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *rear=NULL,*front=NULL;

       void push(int val)
       {
            node *t;
            t=(node*)malloc(sizeof(node));

            if(t==NULL)
            {
                       printf("memory not allocated..");
            }
           t->data=val;
           t->link=NULL;

	         t->link=rear;
	         rear=t;
	         printf("later %d\n",t->data);


      }
       int pop()
       {
           node *t;
           t=(node*)malloc(sizeof(node));
           int val;
           if(rear==NULL)
           {return -1;}
           else{
               t=rear;
           val=t->data;
           rear=rear->link;
           free(t);
           return val;
           }}

           main()
           {
                 int a;
                 push(20);
                 push(40);
                 push(60);
                 a=pop();
                printf("%d ",a);
                  a=pop();
                printf("%d ",a);
                 a=pop();
                printf("%d ",a);


                 getch();
                 }



