#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 	   int data;
 	   struct node *left,*right;
}
node;

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
 
node* max(node *one, node *two)
 {
 	return (one->data>two->data)?one:two;
 }
 

node * find_max_node(node *root)
{
	node *max_node_l,*max_node_r,*max_n=root;
	
	if(root->left||root->right)
	{
		max_node_l=find_max_node(root->left);
		max_node_r=find_max_node(root->right);
        max_n = max(max_node_l,max_node_r);
        max_n=max(root,max_n);
        return max_n;
	}
	return max_n;
	
}

int main()
{
 	node *root;
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	//using global variable
    node *max_n = find_max_node(root);
    printf("Max Node is :%d",max_n->data);
 	
 	getch();
}
