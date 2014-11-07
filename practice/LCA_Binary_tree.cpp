#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node *l,*r;
		node(int data)
		{
			this->data = data;
			l=r=0;
		}
		// FIND LCA
		node *find_LCA(node *root,int d1,int d2)
		{
			if(!root)
			return 0;
			
			if(root->data == d1 || root->data == d2)
			{
			//	cout<<"Found "<<root->data<<endl;
				return root;
			}
			
			
			node *left = find_LCA(root->l,d1,d2);
			node *right =find_LCA(root->r,d1,d2);
			
			if(left && right)
			{
			//	cout<<"Ret "<<root->data<<endl;
				return root;	
			}
			
			if(left)
			{
			//	cout<<"Ret L "<<left->data<<endl;
				return left;
			}
			else
			{
			//	cout<<"Ret R "<<right->data<<endl;
				return right;
			}
		}
		// inorder
		void inorder(node *root)
		{
			if(!root)
			return;
			inorder(root->l);
			cout<<root->data<<" "<<endl;
			inorder(root->r);	
		}
};
int main()
{
	node *root = new node(1);
	root -> l = new node(3);
	root -> r = new node(4);
	root -> l->r = new node(9);
	root -> l->l = new node(0);
	root -> r->l = new node(7);
	root -> r-> r = new node(6);
	
	//root->inorder(root);
	
	node *LCA = root->find_LCA(root,0,0);
	if(LCA)
	{
		cout<<LCA->data;
	}
	else
	{
		cout<<"Doesnt Exist\n";
	}
	return 0;
}


