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
void insert(node *temp,int val)
{

if(temp==NULL)
{
temp->data=val;
temp->right=NULL;
temp->left=NULL;
}
if(temp->data<val)
{
    insert(temp->left,val);
}
if(temp->data>val)
{
    insert(temp->right,val);
}

}
main()
{
node *root,*t;
int val;
char a;
root==(node*)malloc(sizeof(node));
root=NULL;
t=root;
printf("Do You Want enter value in Binary tree?? Y/N\n");
scanf("%c",a);

while((a=='y')||(a=='Y'))
{
scanf("%d",&val);
insert(t,val);
printf("Enter more??Y/N\n");
scanf("%c",a);
t=(node*)malloc(sizeof(node));
}

printf("INORDER REFERENCE\n");
inorder(root);

printf("\nPREORDER REFERENCE\n");
preorder(root);

printf("\nPOSTORDER REFERENCE\n");
postorder(root);
}

