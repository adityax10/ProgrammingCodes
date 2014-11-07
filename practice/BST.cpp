#include<bits/stdc++.h>
using namespace std;

class node{
	public :
		node *l,*r;
		int data;
		node()
		{
			data=0;
			l=r=0;
		}
		
		node(int data)
		{
			this->data = data;
			l=r=0;
		}
		
		node* insert(node *root,int val)
		{
			if(!root)
			{
				root = new node(val);
				return root;
			}
			if(val > root->data)
			root->r = insert(root->r,val);
			else if(val <= root->data)
			root->l = insert(root->l,val);
		}
		void inorder(node *root)
		{
			if(root)
			{
				inorder(root->l);
				cout<<root->data<<" ";
				inorder(root->r);
			}
			else
			return;
		}
		
		node *search(int val)
		{
			node *root = this;
			while(root)
			{
			if(val < root->data)
			root = root->l;
			else if(val> root->data)
			root = root ->r;
			else
			return root;
			}
			node *null_node = new node(-1);
			return null_node;
		}
		
		node *findMax(node *root)
		{
			while(root->r)
			{
				root = root->r;
			}
			return root;
		}
		
		node *delete_node(node *root,int val)
		{
			if(!root)
			{
				cout<<"Node Doesn't Exsist in the tree"<<endl;
				return 0;
			}
			
			//cout<<"Visiting "<<root->data<<endl;
			 
			if(root->data > val)
			root->l = delete_node(root->l,val);
			
			else if(root->data < val)
			root->r = delete_node(root->r,val);
			
			else // NODE TO BE DELETED FOUND
			{
				// IF NODE HAS ONLY ONE CHILD
				if(!root->l && !root->r)
				{
					root=0;
				}
				else if(root->l==0)
				{
					node *temp = root;
					root=root->r;
					free(temp);
				}
				else if(root->r==0)
				{
					node *temp = root;
					root =root->l;
					free(temp);
				}
				else // BOTH CHILD ARE PRESENT
				{
					node *temp = findMax(root->l); // FIND MAX CHILD IN THE LEFT SUB TREE
				//		cout<<"Found "<<val<<" Now deleting "<<temp->data<<endl;
					root->data = temp->data; // SWAP THE DATA OF THE NODE TO BE DELETED WITH MAX VAL IN LEFT SUB TREE
					root->l = delete_node(root->l,temp->data);// DELETE THE MAX NODE
				}
			}
			return root;
		}
		
		node * findLCA(node *root,int n1,int n2)
		{
			if(!root)
			return 0;
			
			if((root->data >= n1 && root->data <= n2) || (root->data <= n1 && root->data >= n2))
			{
				return root;
			}
			else if(root->data < n1 && root->data < n2)
			{
				findLCA(root->r,n1,n2);
			}
			else if(root->data > n1 && root->data > n2)
			{
				findLCA(root->l,n1,n2);
			}
		}
		
		node *cal_floor(node *root,int data,node *prev)
		{
			if(!root)
			{
				return 0;
			}
			if(!cal_floor(root->l,data,prev))
			{
			
			if(root->data > data)
			{
			cout<<"Ret "<<prev->data<<endl;
			return prev;
			}
			
			prev=root;
			
			return cal_floor(root->r,data,prev);
			}
		}
		
		node* kthSmallestValue(node *root,int x,int k)
		{
			if(!root)
			return 0;
			
			node *n = kthSmallestValue(root->l,x,k);
			 if(n)
			 return n;
			 
			 x++;
			if(x == k)
			{
				cout<<"Found "<<root->data<<endl;
				return root;
			}
			
			 else
			 return kthSmallestValue(root->r,x,k);
		}
};

int main()
{
	node *t1= new node(10);
	t1->insert(t1,2);
	t1->insert(t1,12);
	t1->insert(t1,1);
	t1->insert(t1,8);
	t1->insert(t1,10);
	t1->insert(t1,19);
	
	//t1->inorder(t1);
	
	//cout<<t1->cal_floor(t1,5,0)->data; 
	
	cout<<t1->kthSmallestValue(t1,0,3)->data; 
	
	/*
	node *t2 = t1->search(5);
	cout<<"FOUND :"<<t2->data<<endl;
	
	t1->inorder(t1);
	cout<<endl;
	cout<<"MAX : "<<t1->findMax(t1)->data;
	cout<<endl;
	
	t1->delete_node(t1,3);
	// DELETE
	t1->inorder(t1);
	cout<<endl;
	// BEFORE DOING THIS.. CHECK FOR THE PRESENCE OF THE DATA AS STATED IN NODES N1 AND N2 using find
	cout<<t1->findLCA(t1,5,7)->data;
	*/
	return 0;
}


