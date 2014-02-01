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
//x is max_width
int cal_width(node *root,int *x)
{
	if(root)
	{
		printf("Travesing %d and x = %d\n",root->data,*x);
		//height taking left node
		int left = 1+cal_width(root->left,x);
		//height taking right node
		int right = 1+cal_width(root->right,x);
		//-1 cuz root node will be included twice
		if(*x < left+right-1)
		{
		 *x = left+right-1 ;
	    }
		 return max(left,right); 
	}
	return 0;
}


int main()
{
 	node *root;
 	int *x;
 	x=(int*)malloc(sizeof(int));
 	*x=0;
 	int height[10];
 	root = (node*)malloc(sizeof(node));
 	create_tree(root);
 	inorder(root);
 	printf("\n");
 	cal_width(root,x);
    printf("Width of tree id %d",*x);//Radius and width are same thing..
 	getch();
}

