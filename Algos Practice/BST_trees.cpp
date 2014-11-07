#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
};

void insert(node tree[],int i,int val)
{
	node temp;
	if(val==tree[i-1].data)
	return;
	else if(val>tree[i-1].data)
	temp=*(tree+i-1)->right;
	else
	{
		temp=*(tree+i-1)->left;
	}
    temp.data=val;
    printf("value added : %d",temp.data);
}

void insert_values(node tree[],int n)
{
	int val;
	printf("Enter the root node data : ");
	scanf("%d",&tree[0].data);
	for(int i=1;i<=n-1;i++)
	{
        scanf("%d",&val);
		insert(tree,(i+1)/2,val);
	}
}

int main()
{
	node *tree;
	int n,i;
	
	printf("Enter the number of node in the tree : ");
	scanf("%d",&n);
	tree=(node *)malloc(n*sizeof(node));
	printf("Enter the terms -> \n");
	insert_values(tree,n);





  getch();
  return 0;
}


