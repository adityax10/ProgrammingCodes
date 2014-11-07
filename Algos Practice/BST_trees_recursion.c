#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
}node;

void insert(node *tree,int n)
{
	int val;
	scanf("%d",&val);
	
	insert(tree)

}

void insert_values(node tree[],int n)
{
	prinf("Root value : ");
	scanf("%d",&(tree[0].data));
	insert(tree,n);
}



int main()
{
	node *tree;
	int n,i;

	printf("Enter the number of node in the tree : ");
	scanf("%d",&n);
	printf("Enter the terms -> \n");
	insert_values(tree,n);

  getch();
  return 0;
}


