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
     
     root->left=NULL;
     root->right=NULL;
     
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
 
 int level_order_max_Sum(node *root)
 {
 	queue *q;
 	int curr_sum=0,max_sum;
 	q=create_queue();
 	enqueue(q,root);
 	enqueue(q,NULL);
 	max_sum=curr_sum;
 	//prev_level=curr_level;
 	//printf("Level Order Traversal Is: ");
 	while(isNotEmpty(q))
 	{
 		root=dequeue(q);
 		if(root==NULL)
		 {
 			//curr_level++;
 			printf("currSum =%d n MAx =%d\n",curr_sum,max_sum);
 			if(curr_sum > max_sum)
 			max_sum = curr_sum;
 			curr_sum =0;
 			//if cuz to check for boundary case at the end
 			if(isNotEmpty(q))
 			enqueue(q,NULL);
 		 }
 	     else
 		{
 		curr_sum = curr_sum + root->data;
 		printf("SUm is :%d\n",curr_sum);
 		if(root->left)
 		enqueue(q,root->left);
 		if(root->right)
 		enqueue(q,root->right);
 	    }   
	}
 	
 	return max_sum;
 }

int main()
{
 	node *root;
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	printf("Max sum id %d",level_order_max_Sum(root));
 	
 	getch();
}
