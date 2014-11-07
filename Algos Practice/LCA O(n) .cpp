#include<bits/stdc++.h>
using namespace std;

//O(n) bottom up approach
/*
   _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

We traverse from the bottom, and once we reach a node which matches one of the two nodes,
we pass it up to its parent.
The parent would then test its left and right subtree if each contain one of the two nodes.
If yes, then the parent must be the LCA and we pass its parent up to the root.
If not, we pass the lower node which contains either one of the two nodes
(if the left or right subtree contains either p or q),
or NULL (if both the left and right subtree does not contain either p or q) up.
*/

class node
{
	public :
	int data;
	node *l,*r;
	node()
	{
		data=0;
		l=NULL;
		r=NULL;
	}
	node(int d)
	{
		data = d;
		l = r =NULL;
	}
};

node* find_LCA(node *t,int n1,int n2)
{
	if(t==NULL)
	return NULL;
	if(t->data == n1 || t->data== n2)
	return t;
	// look for its childs 
	// formally.. we are going to use this to reach the childs and start our "upward traversal" evaluation as we find 
	// the first matching node for n1 or n2;
	node *L = find_LCA(t->l,n1,n2);
	node *R = find_LCA(t->r,n1,n2);
	
	if(L&&R) //if both are found under the same parent
	return t;
	else if(!L)
	return R; //if left of t didn't turn gave a match for n1 or n2
	else
	return L;
}

int main()
{
	node *root;
	root = new node(1);
	root->l = new node(2);
	root->r= new node(3);
	root->l->l = new node(4);
	root->l->r = new node(5);
	root->l->r->l = new node(8);
	root->l->r->r = new node(9);
	root->l->r->r->r = new node(10);
	
	root->r->l=new node(5);
	root->r->r=new node(7);
	
	cout<<find_LCA(root,4,10)->data;
	
	return 0;
}


