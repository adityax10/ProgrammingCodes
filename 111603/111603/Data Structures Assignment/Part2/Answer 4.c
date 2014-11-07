#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *start=NULL,*end=NULL,*l[4],*s[4];

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
                                     void split(node *list)
                                     {
                                         int n=0;
                                         while((n<4)&&(list!=NULL))
                                         {
                                             s[n]=list;
                                            l[n]=s[n];
                                             list=list->link;
                                             n++;
                                         }
                                         n=0;
                                    while(list!=NULL)
                                     {
                                         n=n%4;
                                         l[n]->link=list;
                                         l[n]=list;
                                         list=list->link;
                                         l[n]->link=NULL;
                                         n++;
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
                                                split(start);
                                                i=0;
                                                while(i<4)
                                                {
                                                printf("\nThe list %d is...:",i+1);
                                                n=s[i];
                                                while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }
                                                    i++;
                                                }


                                                }
