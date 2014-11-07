#include<stdio.h>
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

                      void reverse()
                      {
                      node *p,*c,*n;
                      p=(node*)malloc(sizeof(node));

                      while(n!=NULL)
                      {
                      p=front;
                      front=front->link;
                      c=front;
                      front=front->link;
                      n=front;

                      c->link=p;
                      p=c;
                      c=n;
                      n=n->link;
                      }
                      front=c;
                      }

                                     main()
                                     {
                                     int a,val,b,n,i=0;
                                     printf("How many values do you wanna enter?\n");
                                     scanf("%d",&n);

                                     while(i<n)
                                     {
                                     printf("enetr a value\n");
                                     scanf("%d",&val);
                                     add(val);
                                     i++;
                                     }
                                       reverse();

                                         a=delete();
                                       while(a!=-1)
                                         {
                                        printf("%d ",a);
                                        a=delete();
                                       }}
