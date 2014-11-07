#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	char data;
	node *l,*r;
	node(char data)
	{
		this->data = data;
		l=r=0;
	}
};

node *construct_tree(char in[],char pre[],int s,int e,int n)
{
	cout<<"Called s "<<s<<" e "<<e<<endl;
	static int pre_index = 0;
	
	if(e<s)
	return 0;
	
	node *root = new node(pre[pre_index]);
	pre_index++;
	
	if(e==s)
	return root;
	
	int in_index;
	// find the root node index in inorder
	for(int i=0;i<n;i++)
	{
		if(in[i]==root->data)
		{
		in_index=i;
		break;
		}
	}
	root->l = construct_tree(in,pre,s,in_index-1,n);
	root->r = construct_tree(in,pre,in_index+1,e,n);
	return root;
}

void inorder_traverse(node *t)
{
	if(!t)
	return;
	inorder_traverse(t->l);
	cout<<t->data<<" ";
	inorder_traverse(t->r);
}

int main()
{
	char inorder[]={'D','B','E','A','F','C'};
	char preorder[]={'A','B','D','E','C','F'};
	
	node *t = construct_tree(inorder,preorder,0,sizeof(inorder)/sizeof(char) -1,sizeof(inorder)/sizeof(char));
	inorder_traverse(t);
	
	return 0;
}


