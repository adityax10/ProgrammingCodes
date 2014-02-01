#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;


void create(node **start)
{
    char c;
    node *x;
    printf("Do you wanna enter data??");
    scanf("%c",&c);
    while(c=='y')
    {
    if(*start==NULL)
    {
        *start=(node*)malloc(sizeof(node));
        x=*start;}
    printf("Enter:");
    scanf("%d",&(x->data));
    fflush(stdin);
    printf("Enter more data??y/n");
    scanf("%c",&c);
     fflush(stdin);
    if(c=='y')
    {
        x->link=(node*)malloc(sizeof(node));
        x=x->link;

    continue;
    }
    else
    {
      x->link=NULL;
      break;
    }

}

}
void display(node *temp)
       {

           printf("\nThe List Is:\n");
          while(temp!=NULL)
          {
            printf("%d ",temp->data);
            temp=temp->link;
          }
       }

       concat(node *f,node *s)
       {
           for(;f->link!=NULL;f=f->link);
           f->link=s;
       }

main()
{
    node *list1=NULL;
    node *list2=NULL;
    printf("\nEnter the 1st list!\n");
    create(&list1);
    display(list1);
    printf("\nEnter the 2st list!\n");
    create(&list2);
    display(list2);
    concat(list1,list2);
    display(list1);
}
