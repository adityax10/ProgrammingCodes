#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{

 int data;
 struct node *link;
 }node;
main()
{
node *start,*p;
int x,i=0;
char a;

printf("enter elements??");

start=NULL;
scanf("%d",&a);
   while(a=='y')


{   p=(node*)malloc(sizeof(node));
printf("Enter th values");
    scanf("%d",&(p->data));
    p->link=NULL;
if(start==NULL)
{
start=p;
printf(" %d ",start->data);
}
else
{
p->link=start;
start=p;
printf(" %d ",start->data);
}
printf("Enter more??");
scanf("%d",&a);
}
while(p->link!=NULL)
{
printf(" %d ",p->data);
p=p->link;
}
getch();
}

