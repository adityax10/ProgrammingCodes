#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 	   int data;
 	   struct node *left,*right;
}
node;

typedef struct queue
{
	int front,back;
	node *list[100];
}
queue;

queue* create_queue()
{
	queue *s;
	s=(queue*)malloc(sizeof(queue));
	s->front=0;
	s->back=0;
	return s;
}

node* top(queue *s)
{
	if(s->back <= s->front)
	{
		return (s->list[s->back]); 
	}
	else
	{
		node *null_node;
		null_node = (node*)malloc(sizeof(node));
		null_node->data=-1;
		null_node->left=NULL;
		null_node->right=NULL;
		return null_node;
	}
}

void enqueue(queue *s,node *n)
{
	
	if(s->front < 100)
	{
	//	printf("Pushing!!\n");
	s->list[s->front]=(node*)malloc(sizeof(node));	
	s->list[s->front++]=n;
    }
	else
	{
		printf("No Sapce !!\n");
	}
}


node* dequeue(queue *s)
{
	if(s->back <= s->front-1)
	{
	//	printf("Poping!!\n");
	    //printf("back %d,top %d",s->back,s->front);
		return s->list[s->back++]; 
	}
	else
	{
		//printf("Returning Null Node\n");
		node *null_node;
		null_node=(node*)malloc(sizeof(node));
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

void create_tree(node *root)
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
 		       create_tree(root->left);
            }
           
            fflush(stdin);
             printf("Does %d have a right node ??",root->data);
            scanf("%c",&c);
            if(c=='y')
            {
               root->right= (node*)malloc(sizeof(node));
 		       create_tree(root->right);
            }
            
}

int isNotEmpty(queue *q)
{
	return q->back==q->front?0:1;
}
 
 void level_order(node *root)
 {
 	queue *q;
 	q=create_queue();
 	enqueue(q,root);
 	printf("Level Order Traversal Is: ");
 	while(isNotEmpty(q))
 	{
 		root=dequeue(q);
 		if(root)
 		printf("%d",root->data);
 		if(root->left)
 		enqueue(q,root->left);
 		if(root->right)
 		enqueue(q,root->right);
	}
 	
 }

int main()
{
 	node *root;
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	level_order(root);
 	
 	getch();
}
