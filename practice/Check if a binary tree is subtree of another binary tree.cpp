#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	char data;
	Node *left,*right;
	// CONSTRUCTOR
	Node(char z)
	{
		data = z;
		right=left=0;
	}
	// FIND NODE
	Node *find(Node *p,Node *t)
	{
		if(!p)
		return 0;
		
		if(p->data == t->data)
		return p;
		else
		{
			Node *f1 = find(p->left,t);
			Node *f2 = find(p->right,t);
			return (f1==0)?f2:f1;
		}
	}
	
	// CHECK Equivalency
	bool check(Node *t1,Node *t2)
	{
		if(!t1 && !t2)
		return 1;
		
		if(!t1 || !t2)
		return 0;
		
		cout<<"Checking "<<t1->data<<" "<<t2->data<<endl;
		
		if(t1->data!=t2->data)
		return 0;
		
		if(t1->data == t2->data)
		return check(t1->left,t2->left)&&check(t1->right,t2->right);
	}
	
};


int main()
{
    Node *T = new Node('z');
    T->left = new Node('x');
    T->right = new Node('e');
    T->left->left = new Node('a');
    T->left->right = new Node('b');
    T->right->right = new Node('k');
    T->left->left->right = new Node('c');
 
    Node *S = new Node('x');
    S->left = new Node('a');
    S->right = new Node('b');
    S->left->right = new Node('c');
 
    Node *x = T->find(T,S);
    if(x!=0)
    {
    	if(T->check(x,S))
    	{
    		cout<<"YES\n";
    	}
    	else
    	cout<<"NO\n";
    }
    return 0;
}

