#include<stdio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *start;

    void create(node *t)
       {
        char c;
        printf("Enter data?");
        scanf("%c",&c);
        fflush(stdin);
        if(c=='y')
       {
       printf("Enter :");
         scanf("%d",&(t->data));
         printf("Enter data?");
         fflush(stdin);
        scanf("%c",&c);
        fflush(stdin);
        if(c=='y')
        {t->link=(node*)malloc(sizeof(node));
        create(t->link);}
        else{
            t->link=NULL;
       }}}

    sort(node *list1,node *list2)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        start=temp;
        while((list1!=NULL)&&(list2!=NULL))
        {
        if((list1->data)>(list2->data))
        {
            temp->data=list2->data;
            list2=list2->link;
        }
        else if((list1->data)<(list2->data))
        {
            temp->data=list1->data;
            list1=list1->link;
        }
        temp->link=(node*)malloc(sizeof(node));
        temp=temp->link;
        }
        if(list1==NULL)
        {
        while(list2!=NULL)
        {
        temp->data=list2->data;
        list2=list2->link;
        if(list2==NULL)
        {
            break;
        }
       {temp->link=(node*)malloc(sizeof(node));
        temp=temp->link;}}}
        else if(list2==NULL)
        {
            while(list1!=NULL)
        {
        temp->data=list1->data;
        list1=list1->link;
        if(list1==NULL)
        {
            break;
        }
        temp->link=(node*)malloc(sizeof(node));
        temp=temp->link;}}
    temp->link=NULL;
    }


                                     main()
                                     {
                                         int x,i=0,val,a;
                                         node *list1,*list2,*n;
                                         list1=(node*)malloc(sizeof(node));
                                         list2=(node*)malloc(sizeof(node));

                                         printf("Enter the 1st list in increasing order\n");

                                         create(list1);

                                                n=list1;
                                                while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }
                                        printf("\nEnter the 2nd list in increasing order\n");
                                         create(list2);
                                                    n=list2;
                                                while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }
                                                    sort(list1,list2);
                                                    printf("\nThe sorted list is...\n");
                                                    n=start;
                                                    while(n!=NULL)
                                                    {
                                                    printf(" %d ",n->data);
                                                    n=n->link;
                                                    }

                                                    }


