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



                                     void insert(int val,int b)
                                     {
                                     node *t,*start;
                                     int i;
                                     t=(node*)malloc(sizeof(node));
                                     t->data=val;


                                     if(b==0)
                                     {
                                     t->link=front;
                                     front=t;
                                     }
                                     else
                                     {
                                     start=front;

                                     for(i=0;i<b-1;i++)
                                     {

                                     front=front->link;
                                     }
                                     t->link=front->link;
                                     front->link=t;
                                     }
                                     front=start;
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

                                     printf("Enter the position to insert a value(less than %d)",n);
                                     scanf("%d",&b);

                                     printf("enetr a value\n");
                                     scanf("%d",&val);

                                     insert(val,b);

                                       a=delete();
                                       while(a!=-1)
                                         {
                                        printf("%d ",a);
                                        a=delete();
                                         }


                                     }

