#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
       {
       int data;
       struct node *link;
       }node;
       node *l,*r;
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

}}

void display(node *temp)
       {

           printf("\nThe List Is:\n");
          while(temp!=NULL)
          {
            printf("%d ",temp->data);
            temp=temp->link;
          }
       }


       void move_right(int pos,node *current)
       {
           int x=pos-1;
           node *p=NULL;
           l=current;
                       while(x>=0)
                       {
                        l->link=p;
                        p=l;
                        l=r;
                        r=r->link;
                        x--;
                       }
       }

main()
{
    node *list1=NULL;
    int pos;
    char c;
    printf("Enter the list!\n");
    create(&list1);
    display(list1);
    printf("Enter the positon of the current node in the linked list...\n");
    scanf("%d",&pos);

    move_right(pos,&list1);
    printf("Where do you wanna shift??left(-)\right(+)..\n");
    scanf("%c",&c);
    printf("Enter the positiion of node to which you want to go\n");
    scanf("%d",&pos);
    switch(c)
    {
    case '+':
    move_right(pos,&list1);
    display(list1);
}
}
