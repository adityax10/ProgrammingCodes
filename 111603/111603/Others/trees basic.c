#include<stdio.h>

typedef struct node{
int data;
struct node *left,*right;
}node;

void inorder(node *t)
{

    if(t!=NULL)
    {
    inorder(t->left);
    printf("%d\t",t->data);
    inorder(t->right);
    }
}

void preorder(node *t)
{
    if(t!=NULL)
    {
    printf("%d\t",t->data);
    preorder(t->left);
    preorder(t->right);
    }
}

void postorder(node *t)
{
    if(t!=NULL)
    {
    postorder(t->left);
    postorder(t->right);
    printf("%d\t",t->data);
    }
}

main()
{
node *bt1,*temp,*temp2;

bt1=(node*)malloc(sizeof(node));

bt1->data=20;

temp=(node*)malloc(sizeof(node));
bt1->left=temp;

temp->data=10;
temp->left=NULL;
temp->right=NULL;

temp2=(node*)malloc(sizeof(node));
bt1->right=temp2;

temp2->data=30;
temp2->left=NULL;
temp2->right=NULL;
printf("INORDER REFERENCE\n");
inorder(bt1);

printf("\nPREORDER REFERENCE\n");
preorder(bt1);

printf("\nPOSTORDER REFERENCE\n");
postorder(bt1);
}

