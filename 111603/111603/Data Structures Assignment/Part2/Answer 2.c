#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{

int data;
struct node *left,*right;
}node;
node *start=NULL,*end=NULL;

void add(int val)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    if(end==NULL)
    {
        start=temp;
        end=start;
    }
    else
    {
        end->right=temp;
        temp->left=end;
        end=temp;
    }
}
void delete(node *temp)
{
if(temp==start)
{
    start=start->right;
}
else if(temp==end)
{
    end=end->left;
    end->right=NULL;
}
}

void insert(int val,node *t)
{
    printf("entered into insert function");
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    if(t==start)
    {
        printf("ENtered with start");
        temp->right=start;
        start->left=temp;
        start=temp;
    }
    else if(t==end)
    {
        printf("Entered at the end");
        end->right=temp;
        temp->left=end;
        end=temp;
    }
}

main()
{
 int i=0,val,a,r;
node *n;
char c;
printf("Enter the no values in nodes..\n");
scanf("%d",&a);
printf("Enter the values\n");
for(i=0;i<a;i++)
{
scanf("%d",&val);
add(val);
}
n=start;
while(n!=NULL)
    {
    printf(" %d ",n->data);
    n=n->right;
    }

fflush(stdin);
printf("Insertion or deletion?\nPress\ni to insert\nd to delete\n");
scanf("%c",&c);
switch(c)
{
case 'd':
fflush(stdin);
printf("\n\n<Deletion from node>\nPRESS :\nl for left\nr for right\nx to exit\n");
scanf("%c",&c);

printf("\nInput = %c\n",c);
while(c!='x')
{
if(c=='l')
{delete(start);}
else if(c=='r')
{delete(end);}
printf("Deletion Complete!");
printf("\n\n<Further Deletion from node?>\nPRESS :\nl for left\nr for right\nx to exit\n");
scanf("%c",&c);
}break;
case 'i':
fflush(stdin);
printf("\n\n<Insertion in node list?>\nPRESS :\nl for left\nr for right\nx to exit\n");
scanf("%c",&c);
printf("\nInput = %c\n",c);
while(c!='x')
{
printf("Enter the value to be inserted\n");
scanf("%d",&val);

switch (c)
{
case 'l':
printf("c=l entered in switch"); insert(val,start); break;
case 'r':
{insert(val,end);}}
printf("Insertion Complete!");
printf("\n\n<Further Insertion in node list?>\nPRESS :\nl for left\nr for right\nx to exit\n");
scanf("%c",&c);
}
}
n=start;
while(n!=NULL)
    {
    printf(" %d ",n->data);
    n=n->right;
    }
}

