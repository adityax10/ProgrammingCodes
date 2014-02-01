#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *link;
}node;
main()
{
    char a;
    int x;
node *start,*temp1,*temp2;

start=(node*)malloc(sizeof(node));
start->data=3;
temp1=(node*)malloc(sizeof(node));
start->link=temp1;

temp1->data=6;
temp2=(node*)malloc(sizeof(node));
temp1->link=temp2;


temp2->data=0;
temp2->link=NULL;



temp1=start;
while(temp1->link!=NULL)
{
printf(" %d ",temp1->data);
temp1=temp1->link;
}
}




