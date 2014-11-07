#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 	   int data;
 	   struct node *left,*right;
}
node;

typedef struct stack
{
	int top;
	
	node *list[100];
}
stack;

stack* create_stack()
{
	stack *s;
	s=(stack*)malloc(sizeof(stack));
	s->list[0]=(node*)malloc(sizeof(node));
	s->top=0;
	node *null_node;
		null_node->data=-1;
		null_node->left=NULL;
		null_node->right=NULL;
		
	s->list[0]=null_node;
	return s;
}

node* top(stack *s)
{
	if(s->top >0&&s->top <100)
	{
		return (s->list[s->top]); 
	}
}

void push(stack *s,node *n)
{
	
	if(s->top+1< 100)
	{
	//	printf("Pushing!!\n");
	s->top++;
	s->list[s->top]=(node*)malloc(sizeof(node));	
	s->list[s->top]=n;
    }
	else
	{
		printf("No Sapce !!\n");
	}
}


node* pop(stack *s)
{
	if(s->top > 0&&s->top <100)
	{
	//	printf("Poping!!\n");
		return s->list[s->top--]; 
	}
	else
	{
		node *null_node;
		null_node->data=-1;
		null_node->left=NULL;
		null_node->right=NULL;
		return null_node;
	}
}

void inorder(node *root)
{
	
 	if(root)
 	{
 		//printf("traverring...%d\n",root->data);
 		//getch();
	 		inorder(root->left);
	 		printf("%d",root->data);
	 		inorder(root->right);
 	}
 	else
 	return;
}

void create_node(node *root)
{
     char c;
    // if(root==NULL)
     {
     
     root->left=NULL;
     root->right=NULL;
     }
     printf("Enter the node \n");
     scanf("%d",&(root->data));
  
            printf("Does %d have a left node ??",root->data);
            fflush(stdin);
            scanf("%c",&c);
            if(c=='y')
            {
            	root->left= (node*)malloc(sizeof(node));
 		       create_node(root->left);
            }
           
            fflush(stdin);
             printf("Does %d have a right node ??",root->data);
            scanf("%c",&c);
            if(c=='y')
            {
               root->right= (node*)malloc(sizeof(node));
 		       create_node(root->right);
            }
            
}


void preorder(node *root)
{
	int parent_counter=0;
	printf("Doing Preorder\n");
	stack *s;
	s=create_stack();
	while(1)
	{
		getch();
		//printf("Stack TOP = %d",s->top);
		if(root)
		{
			push(s,root);
			root=root->left;
		}
		else
		{
			if(s->top==0)
			{
				return;
			}
			else if(top(s)->right==NULL)
			{
			//	printf("Top right is NULL\n");
			root=pop(s);
			printf(" %d ",root->data);
			
			if(root==top(s)->right)
			{
				root = pop(s);
				printf(" %d ",root->data);
			}
		   }
		   if(s->top==1)
		   {
		   	if(s->top->right==NULL)
		   	break;
		   parent_counter++;
	       }
		   if(parent_counter==2)
		   {
		   	root = pop(s);
		   	printf(" %d ",root->data);
		   	break;
		   }
		   if(s->top > 0)
		   root=top(s)->right;
		      
		}
	}
}

int main()
{
 	node *root;
 	root = (node*)malloc(sizeof(node));
 	create_node(root);
 	inorder(root);
 	
 	preorder(root);
 	
 	getch();
}
