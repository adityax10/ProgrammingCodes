#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *rear=NULL,*front=NULL;

       void add(int val)
       {
            node *t;
            t=(node*)malloc(sizeof(node));

            if(t==NULL)
            {
                       printf("memory not allocated..");
                       }
                         t->data=val;
                       t->link=NULL;
                       if(rear==NULL)
                       {
                           front=t;
                           rear=t;
                           printf("intially %d\n",t->data);
                       }

                                     else{
                                     rear->link=t;
                                     rear=t;
                                     printf("later %d\n",t->data);
                                     }
                                     }
       int delete()
       {
           node *t;
           t=(node*)malloc(sizeof(node));
           int val;
           if(front==NULL)
           {return -1;}
           else{
               t=front;
           val=t->data;
           front=front->link;
           free(t);
           return val;
           }}

           main()
           {
                 int a;
                 add(20);
                 add(40);
                 add(60);
                 a=delete();
               while(a!=-1)
                 {
                printf("%d ",a);
                a=delete();
                 }
                 getch();
                 }



