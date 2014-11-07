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

int max(int one, int two)
 {
 	return (one>two)?one:two;
 }


int find_height_tree(node *root)
{
    if(root->left==NULL&&root->right==NULL)
    return 0;

	if(root)
	{
		return (1+max(find_height_tree(root->left),find_height_tree(root->right)));
	}
	return 0;
}

int find_height_node(node *root,int height[])
{
    if(root->left==NULL&&root->right==NULL)
    {
    height[root->data]=0;
    return 0;
    }

	if(root)
	{
		int h = (1+max(find_height_node(root->left,height),find_height_node(root->right,height)));
		height[root->data]=h;
	}
}

int main()
{
 	node *root;
 	int height[10];
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	//using global variable
    printf("Height of tree is :%d\n",find_height_tree(root));

    find_height_node(root,height);
    printf("Height of node %d is :%d\n",5,height[5]);
 	getch();
}
