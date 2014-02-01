/////  each node has a count of the nodes in its sub tree.//////////
//////////////////////////////////////////////////////////////////////
///// count deontes the number of node in the sub tree +1;/////////////
/////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
int count;
struct node *left,*right;
}node;

void inorder(node *t)
{

    if(t!=NULL)
    {
    inorder(t->left);
    printf("%d & %d\t",t->data,t->count);
    inorder(t->right);
    }
}

int create(node **temp)
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
		t->count=1;
	}
	//left node
    fflush(stdin);
	printf("Does %d have a left node ? \n",t->data);
	scanf("%c",&c);
	if((c=='y')||(c=='Y'))
	{
		t->count=create(&(t->left))+t->count;
	}
	//right node
	fflush(stdin);
	printf("Does %d have a right node ? \n",t->data);
	scanf("%c",&c);
	if((c=='y')||(c=='Y'))
	{
		t->count=create(&(t->right))+t->count;
	}
	
	return (t->count);

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


main()
{
node *root;
int val;
char a;
root=NULL;

create(&root);

printf("INORDER TRAVERSAL\n");
inorder(root);


getch();
}
