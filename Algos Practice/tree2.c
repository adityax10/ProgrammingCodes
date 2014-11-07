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

create(node **temp)
{
	char c;
	int val;
	node *t;
	printf("Enter : ");
	scanf("%d",&val);
	//parent node
	if(*temp==NULL)
	{
		//printf("Assingning val to node null\n");
		*temp=(node *)malloc(sizeof(node));
		t=*temp;
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
		create(&(t->left));
	}
	//right node
	fflush(stdin);
	printf("Does %d have a right node ? \n",t->data);
	scanf("%c",&c);
	if((c=='y')||(c=='Y'))
	{
		create(&(t->right));
	}

}

int search(node *t,int val)
{
	if(t!=NULL)
	{
		if(t->data==val)
		{
			return 1;
		}
		if(val<t->data)
		search(t->left,val);
		else
		search(t->right,val);
	}
}
//not working//
void insert(node *tree,int val)
{
	if(tree!=NULL)
    {
		if(val>tree->data)
		insert(tree->right,val);
		else if(val<tree->data)
		insert(tree->left,val);
	}
	else
	{
		tree=(node*)malloc(sizeof(node));
		tree->data=val;
		tree->left=NULL;
		tree->right=NULL;
	}

}

main()
{
node *root;
int val;
char a;
root=NULL;

create(&root);

printf("INORDER TRAVERSAL\n");
inorder(root);

printf("\nPREORDER TRAVERSAL\n");
preorder(root);

printf("\nPOSTORDER TRAVERSAL\n");
postorder(root);

printf("Enter a value to be searched in the tree : \n");

if(search(root,val)==1)
{
	printf("Value Found ! \n");
}
else
{
	printf("No value exists : \n");
}

printf("Enter an element to be inserted : ");
scanf("%d",&val);
insert(root,val);

printf("INORDER TRAVERSAL\n");
inorder(root);

getch();
}
