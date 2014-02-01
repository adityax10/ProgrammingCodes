#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *start=NULL,*end=NULL;

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
                       if(end==NULL)
                       {
                           start=t;
                           end=t;
                           printf("intially %d\n",t->data);
                       }

                                     else{
                                     end->link=t;
                                     end=t;
                                     printf("later %d\n",t->data);
                                     }
                                     }

                                     void remove_odd(node *p)
                                     {
                                     node *temp;
                                     while((p->link!=NULL)&&(temp->link!=NULL))
                                     {
                                     if(p==start)
                                     {
                                     p=start->link->link;
                                     start=start->link;
                                     temp=start;
                                     printf("initially temp =%d\n",temp->data);
                                     }
                                     else
                                     {
                                     temp->link=p->link;
                                     temp=p->link;
                                     if(temp->link!=NULL)
                                     p=temp->link;
                                     if(p->link==NULL)
                                     {
                                         temp->link=NULL;                                     }
                                      printf("later temp =%d\n",temp->data);
                                     }
                                     }}
                                     main()
                                     {
                                         int x,i=0,val,a;
                                         node *n;
                                                printf("Enter the no values to be added..\n");
                                                scanf("%d",&a);
                                                printf("Enter the values");
                                                for(i=0;i<a;i++)
                                                {
                                                 scanf("%d",&val);
                                                add(val);
                                                 }
                                                n=start;
                                                while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }
                                                remove_odd(start);
                                                n=start;
                                                while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }

                                                }
