#include<bits/stdc++.h>
using namespace std;

//O(n2) top down approach
/*
   _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
         
A Top-Down Approach (Worst case O(n2) ):
Let’s try the top-down approach where we traverse the nodes from the top to the bottom. 
First, if the current node is one of the two nodes, it must be the LCA of the two nodes.
If not, we count the number of nodes that matches either p or q in the left subtree (which we call totalMatches).
If totalMatches equals 1, then we know the right subtree will contain the other node.
Therefore, the current node must be the LCA.
If totalMatches equals 2, we know that both nodes are contained in the left subtree,
so we traverse to its left child. 
Similar with the case where totalMatches equals 0 where we traverse to its right child.
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

// used to find the node n1 and n2 by brute force
// returns 2 if both nodes are found... else returns 1 if only single node is found... otherwise 0
//comlexity N
int find(node *t,int n1,int n2)
{
	if(t==NULL)
	return 0;
	int found = find(t->l,n1,n2) + find(t->r,n1,n2);
	if(t->data==n1 || t->data==n2)
	return found+1;
	else
	return found;
}

// find LCA using find()
//complexity N^2
int find_LCA(node *t,int n1,int n2)
{
	
	if(t==NULL)
	return -1;
	
	if(t->data ==n1 || t->data ==n2)
	return t->data;
	// checking if any one of n1 or n2 exisits in the node t's left
	int found_left = find(t->l,n1,n2);
	
	cout<<"Found left for "<<t->data<<" "<<found_left<<endl;
	
	if(found_left==1)
	return t->data;
	else if(found_left==2)
	return find_LCA(t->l,n1,n2);
	else// if(found_left == 0)
	{
	return	find_LCA(t->r,n1,n2);
	}

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
	
	cout<<find_LCA(root,4,10);
	
	return 0;
}


