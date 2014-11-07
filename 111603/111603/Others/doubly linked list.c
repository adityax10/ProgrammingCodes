#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{

int data;
struct node *b,*n;
}node;


main()
{
node *start,*temp,*end;

start=(node*)malloc(sizeof(node));
temp=(node*)malloc(sizeof(node));
end=(node*)malloc(sizeof(node));

start->data=2;
start->n=temp;
start->b=NULL;

temp->data=3;
temp->n=end;
temp->b=start;

end->data=4;
end->n=NULL;
end->b=temp;

temp=start;
while(temp!=NULL)
{
    printf(" %d ",temp->data);
    temp=temp->n;
}
temp=end;
printf("\nReverse is...\n");
while(temp!=NULL)
{
    printf(" %d ",temp->data);
    temp=temp->b;
}

}

