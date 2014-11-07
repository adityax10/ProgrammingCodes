#include<stdio.h>
#include<stdlib.h>

#define MAX 32767

typedef struct node
{
	int x,y;
	struct node *left,*right;
	int marked;
}node;



void add(node **root,int x,int y)
{
	node *p;
	if(*root)
	{
		p=*root;
		if(p->x==x && p->y==y)
		return;
	}
	else if(*root==NULL)
	{
		*root = (node *)malloc(sizeof(node));
		p=*root;
		p->x=x;
		p->y=y;
		p->left=NULL;
		p->right=NULL;
		return;
	}
	p=*root;
	if(x>=p->x)
	{
		//p->left=add(node*)malloc(sizeof(node));
		add((&(p->right)),x,y);
	}
	else
	{
		add((&(p->left)),x,y);
	}
}

void delete_node(node *present,node *parent)
{
	if(present->right)
	{
		present->x=present->right->x;
		present->y=present->right->y;
		delete_node(present->right,present);
	}
	else if(present->left)
	{
		present->x=present->left->x;
		present->y=present->left->y;
		delete_node(present->left,present);
	}
	else
	{
		//printf("Case 3 parent %d %d and present %d %d \n",parent->x,parent->y,present->x,present->y);
		//error here.>!!
		
		if(parent->left && parent->x == parent->left->x && parent->y == parent->left->y)
		{ 
		//printf("c 3a\n");
			//printf("Deleting node %d %d\n",present->x,present->y);
			parent->left=NULL;
			free(present);
			return;
		}
		else if(parent->right && parent->x == parent->right->x && parent->y == parent->right->y)
		{
			//printf("c 3b\n");
			//printf("Deleting node %d %d\n",present->x,present->y);
			parent->right=NULL;
			free(present);
			return;
		}
		else //if left and right of present are NULL // ie the present is the leaf node and no excange has taken palce b/w the parent and poreasent
		{
			//printf("case in \n");
			if(parent->x >= present->x)
			{
			parent->left=NULL;
			free(present);
		    }
		    else
		    {
		    parent->right=NULL;
			free(present);	
		    }
		    printf("Done.!");
		    return;
		}
		
	}
}


void erase(node *present,node *parent,int x,int y)
{
	while(1)
	{
		if(present)
		{
			if(x==present->x && y==present->y)
			{
				break;
			}
			parent = present;
			if(x <= present->x)
			{
				present = present->left;
			}
			else if(x> present->x)
			{
				present=present->right;
			}
		}
	}

	//printf("Got parent %d %d and todelete %d %d\n",parent->x,parent->y,present->x,present->y);
	delete_node(present,parent); 
}

void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d %d\n",root->x,root->y);
		inorder(root->right);
	}
}

int bottom_x=MAX;
int bottom_y=MAX;
int max_x,min_x;
node *save_parent;

int cal_max_x(node *root)
{
   if(root && root->right)
   return cal_max_x(root->right);
   //if(root && root->left)
   //return cal_max_x(root->left);
   return (max_x=root->x);
}
	
/*int get(node *root,int x,int y)
{
	if(x>=max_x)
	return printf("-1\n");
	
	if(root)
	{
		printf("Currently at : %d %d\n",root->x,root->y);
		if(root->x!=x && root->x >x )
		{
			if(bottom_x == MAX || ( root->x >x && bottom_x <x ))
			{
				bottom_x=root->x;
				bottom_y=root->y;
			}
			else if(bottom_y > root->y && root->y > y)
			{
			bottom_x=root->x;
			bottom_y=root->y;
		    }

			printf("bxy %d %d\n",bottom_x,bottom_y);
			
			if(!root->left && !root->right)
			{
			 return	printf("%d %d\n",bottom_x,bottom_y);
			
			}
		}
		else if(root->x==x)
		{
			if(!root->right)
			{
				return printf("%d %d\n",bottom_x,bottom_y);
			}
		}
		/*else if(root && root->x==x)
		{
			while(root)
			{
				if(root->left && !root->right )
				{
				root=root->left;
				if(root->x==x)
				{
					if(root->y > y)
					{
						bottom_y=root->y;
					}
				}
				else
				break;
				}
				else
				{
					return printf("%d %d",bottom_x,bottom_y);
				}
			}
			return printf("%d %d",bottom_x,bottom_y);
		}
		save_parent=root;
		if(x>=root->x)
		{
			printf("T R\n");
			get(root->right,x,y);
		}
		else
		{
			printf("T L\n");
			get(root->left,x,y);
		}
		//printf("%d %d",root)
	}
	
}*/

int get(node *root,int x,int y)
{
	
	if(x>=max_x || !root)
	{
		return printf("-1\n");
	}
	
	if(root)
	{
		printf("Currently at : %d %d\n",root->x,root->y);
		if(root->x > x)
		{
			if(bottom_x==MAX || bottom_x >= root->x ) 
			{
				if((bottom_y==MAX || bottom_y >root->y )&& root->y > y)
				{
				bottom_x =root->x;
				bottom_y=root->y;
				//printf("temp bottom %d %d\n",bottom_x,bottom_y);
				if(!root->left && !root->right)
			    {
			     if(bottom_x!=MAX && bottom_y!=MAX)
			     return	printf("%d %d\n",bottom_x,bottom_y);
			     else
			     return -1;
		        }
		        }
				
			}
		}
		
		if(root->x <= x && root->right)
		{
			//printf("T R\n");
			int val;
			val = get(root->right,x,y);
			if( val!=3 || val!=-1 )
			{
				if(root->left)
				get(root->left,x,y);
			}
		}
		else if(root->left)
		{
			//printf("T L\n");
			
			int val=get(root->left,x,y);
			if( val!=3||val!=-1 )
			{
				if(root->right)
				get(root->right,x,y);
			}
		}
	}
	
}


int call()
{
	int count,i=0,x,y;
	char c[10];
	node *root=NULL;
	
	
	while(1)
	{
			scanf("%s %d %d",&c,&x,&y);
			//printf("%s %d %d",c,x,y);
			if(c[0]=='a')
			{
				add(&root,x,y);
			}
			else if(c[0]=='e')
			{
				erase(root,root,x,y);
			}
			else if(c[0]=='g')
			{
				cal_max_x(root);
				bottom_x=MAX;
				bottom_y=MAX;
				get(root,x,y);
			}
		//	inorder(root);
	
   }
	
	return 0;
}
