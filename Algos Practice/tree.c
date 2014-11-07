#include<stdio.h>
#include<stdlib.h>

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
/*void insert(node *temp,int val)
{
	if(temp==NULL)
	{
		temp=(node *)malloc(sizeof(node));
		temp->data=val;
		temp->right=NULL;
		temp->left=NULL;
	}
	if(temp->data>val)
	{
		insert(temp->left,val);
	}
	else if(temp->data<val)
	{
		insert(temp->right,val);
	}

}*/

create(node *t)
{
	char c;
	int val;
	printf("Enter : ");
	scanf("%d",&val);
	//parent node
	//if(t==NULL)
	{
		//printf("Assingning val to node null\n");
		//t=(node *)malloc(sizeof(node));
		t->data=val;
		t->left=NULL;
		t->right=NULL;
	}
	//left node
    fflush(stdin);
	printf("Does %d have a left node ? \n",t->data);
	scanf("%c",&c);
	if((c=='y')||(c=='Y'))
	{
		t->left=(node *)malloc(sizeof(node));
		create(t->left);
	}
	//right node
	fflush(stdin);
	printf("Does %d have a right node ? \n",t->data);
	scanf("%c",&c);
	if((c=='y')||(c=='Y'))
	{
		t->right=(node *)malloc(sizeof(node));
		create(t->right);
	}
	
}


main()
{
node *root;
int val;
char a;
root=(node*)malloc(sizeof(node));

create(root);

printf("INORDER TRAVERSAL\n");
inorder(root);

printf("\nPREORDER TRAVERSAL\n");
preorder(root);

printf("\nPOSTORDER TRAVERSAL\n");
postorder(root);

getch();
}
