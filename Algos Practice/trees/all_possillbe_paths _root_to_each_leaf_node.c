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

print_path(int path[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d ",path[i]);
	}
	printf("\n");
}
 
 void find_paths(node *root,int path[],int len)
 {
 	if(root)
 	{
    //printf("%d ",root->data);
 	path[len]=root->data;
 	len++;
    }
 	
 	if(root->left||root->right)
 	{
 		find_paths(root->left,path,len);
 		find_paths(root->right,path,len);
 	}
 	
 	if(root->left==NULL && root->right==NULL)
 	{
 		print_path(path,len);
 		return;
 	}

 }

int main()
{
 	node *root;
 	int len=0,path[10];
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	
 	find_paths(root,path,0);
 	
 	getch();
}
