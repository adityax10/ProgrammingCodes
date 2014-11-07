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

void inorder(node *t)
{
	if(!t)
	return;
	inorder(t->l);
	cout<<t->data<<" ";
	inorder(t->r);
}

node *make_mirror(node *t)
{
	if(!t)
	return 0;
	
	node *m = new node(t->data);
	m->l = make_mirror(t->r);
	m->r= make_mirror(t->l);
	return m;
}

bool check_mirrors(node *t1,node *t2)
{
	if(!t1 && !t2)
	return 1;
	if(!t1 || !t2)
	return 0;
	if(t1->data!=t2->data)
	return 0;
	
	return check_mirrors(t1->l,t2->r) && check_mirrors(t1->r,t2->l);
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
	
	node *m = make_mirror(t);
	
	inorder(t);
	cout<<endl;
	inorder(m);
	cout<<endl;
	cout<<check_mirrors(t,m);
	return 0;
}


