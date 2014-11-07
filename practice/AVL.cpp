#include<bits/stdc++.h>
using namespace std;

class node
{
	public : 
	int data;
	int height;
	node *left,*right;
	// --------------------- CONSTRUCTOR -----------------------------------
	node(int data)
	{
		this->data = data;
		height = 1;
		left = right = 0;
	}
	//------------------------ getHeight --------------------------------
	int getHeight(node *l)
	{
		if(!l)
		return 0;
		else
		return l->height;
	}
	// ------------------------ ROTATIONS ----------------------------------
	// LL
	node* LL(node *root)
	{
		node *t = root->left;
		root->left = t->right;
		t->right = root;
		t->height = max(getHeight(t->left),getHeight(t->right))+1;
		root->height = max(getHeight(root->left),getHeight(root->right))+1;
		return t;
	}
	// RR
	node *RR(node *root)
	{
		node *t = root->right;
		root->right = t->left;
		t->left = root;
		t->height = max(getHeight(t->left),getHeight(t->right))+1;
		root->height = max(getHeight(root->left),getHeight(root->right))+1;
		return t;	
	}
	// LR
	node* LR(node *root)
	{
		// first do RR on root root->left
		// then do LL on root
		root->left = RR(root->left);
		return LL(root);
	}
	// Rl
	node* RL(node *root)
	{
		// first do LL on root root->right
		// then do RR on root
		root->right = LL(root->right);
		return RR(root);
	}
	// --------------------------- INSERT --------------------------
	node *insert(node *root,int data)
	{
		// PLACE FOUND FOR INSERTION
		if(!root)
		{
			root = new node(data);
			return root;
		}
		if(data < root->data)
		{
			root->left = insert(root->left,data);
		}
		else if(data > root->data)
		{
			root->right = insert(root->right,data);
		}

		// CHECK IF ROTATION IS POSSIBLE
		if(getHeight(root->left)-getHeight(root->right)==2)
		{
			if(data < root->left->data)
			root = LL(root);
			else
			root = LR(root);
		}
		// CHECK IF ROTATION IS POSSIBLE
		else if(getHeight(root->right)-getHeight(root->left)==2)
		{
			if(data > root->right->data)
			root = RR(root);
			else
			root = RL(root);
		}
		
		// UPDATE THE HEIGHTS
		root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
		return root;
	}
	// ------------------------------ TRAVERSAL -------------------------------
	void inorder(node *root)
	{
		if(!root)
		return ;
		inorder(root->left);
		cout<<"Data "<<root->data<<" Height "<<root->height<<endl;
		inorder(root->right);
	}
	// ---------------------------- MAX VALUE --------------------------------
	node *findMax(node *root)
	{
		while(root->right)
		{
			root = root->right;
		}
		return root;
	}
	// ------------------------------- DELETE NODE -------------------------------------
	node *delete_node(node *root,int val)
	{
		if(!root)
		{
			cout<<"Node Doesn't Exsist in the tree"<<endl;
			return 0;
		}
		//cout<<"Visiting "<<root->data<<endl;
		 
		if(root->data > val)
		{
			root->left = delete_node(root->left,val);
		}
		else if(root->data < val)
		{
			root->right = delete_node(root->right,val);
		}
		
		else // NODE TO BE DELETED FOUND
		{
			// LEAF NODE
			if(!root->left && !root->right)
			{
				root=0;
			}
			// IF NODE HAS ONLY ONE CHILD
			else if(root->left==0)
			{
				node *temp = root;
				root=root->right;
				free(temp);
			}
			else if(root->right==0)
			{
				node *temp = root;
				root =root->left;
				free(temp);
			}
			else // BOTH CHILD ARE PRESENT
			{
				node *temp = findMax(root->left); // FIND MAX CHILD IN THE LEFT SUB TREE
			//		cout<<"Found "<<val<<" Now deleting "<<temp->data<<endl;
				root->data = temp->data; // SWAP THE DATA OF THE NODE TO BE DELETED WITH MAX VAL IN LEFT SUB TREE
				root->left = delete_node(root->left,temp->data);// DELETE THE MAX NODE
			}
		}
		
		if(root)
		{
			// CHECK IF ROTATION IS POSSIBLE on LEFT
			if(getHeight(root->left)-getHeight(root->right)==2)
			{
				if(data < root->left->data)
				root = LL(root);
				else
				root = LR(root);
			}
			// CHECK IF ROTATION IS POSSIBLE on RIGHT
			else if(getHeight(root->right)-getHeight(root->left)==2)
			{
				if(data > root->right->data)
				root = RR(root);
				else
				root = RL(root);
			}
			root->height = max(getHeight(root->left),getHeight(root->right))+1;
		}
		return root;
	}
};

int main()
{
	/*node *tree;
	tree = new node(8);
	tree = tree->insert(tree,6);
	tree = tree->insert(tree,3);
	tree = tree->insert(tree,2);
	tree->insert(tree,15);
	tree->insert(tree,19);
	tree->insert(tree,29);*/
	
	node *root= new node(10);
	//root = root->insert(root, 10);
	root = root->insert(root, 20);
	root = root->insert(root, 30);
	//root = root->insert(root, 40);
	//root = root->insert(root, 50);
	root = root->insert(root, 25);
	root = root->delete_node(root,20);
	root = root->delete_node(root,10);
	root = root->delete_node(root,25);
	root = root->delete_node(root,20);
	
	//cout<<tree->data;
	//cout<<tree->left->data;
	//cout<<tree->right->data;
	root->inorder(root);
	return 0;
}


