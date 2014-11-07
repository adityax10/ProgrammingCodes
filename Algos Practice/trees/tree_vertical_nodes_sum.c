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

int traversed[200];

/*int v_sum(node *root)
{
	
	if(!root)
	return;
	
	
	if(root)
	{
		printf("Traversing node %d\n",root->data);
		
		int q = root->data;
	
		if(root->left && root->right && root->left->right && root->right->left)
		{
			traversed[root->data]=1;
			q = q + v_sum(root->left->right)+v_sum(root->right->left);
			printf("Sum is %d\n",q);
			if(traversed[root->left->data]==0)
			v_sum(root->left);
			if(traversed[root->right->data]==0)
			v_sum(root->right);
		}
		else if(root->left && root->left->right)
		{
			traversed[root->data]=1;
			q = q + v_sum(root->left->right);
			printf("Sum is %d\n",q);
			if(traversed[root->left->data]==0)
			v_sum(root->left);
		}
		else if (root->right && root->right->left)
		{
			q = q + v_sum(root->right && root->right->left);
			printf("Sum is %d\n",q);
			if(traversed[root->right->data]==0)
			v_sum(root->right);
		}
		else if(!root->left && !root->right)
		{
			printf("Sum is %d\n",q);
		}
		
			traversed[root->data]=1;
		//printf("Sum is %d\n",q);
		return q;
	}
	
}*/

int col_sum[100];

int v_sum(node *root,int col)
{
	if(!root)
	return ;
	
	v_sum(root->left,col+1,);
	col_sum[col]+=root->data;
	v_sum(root->right,col-1);
}


int main()
{
 	node *root;
 	int height[10];
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	
 	int x = v_sum(root,0);
 	
 
 
}

