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
};
int dia = 0;
int diameter(node *t)
{
	if(!t)
	return 0;
	
	// left nad right sub tree heights
	int left = 1+diameter(t->l);
	int right = 1+diameter(t->r);
	
	// dia will be max
	dia = max(left+right-1,dia);
	
	// return the max height
	return max(left,right);
}

int main()
{
	node *t;
	t = new node(1);
	t->l = new node(2);
	t->r = new node(3);
	t->l->l = new node(4);
	t->l->r = new node(5);
	t->r->l = new node(6);
	t->r->r = new node(7);
	t->r->l->r=new node(12);
	t->r->l->l=new node(13);
	t->r->l->r->l = new node(11);
	diameter(t);
	cout<<dia<<endl;
	return 0;
}


