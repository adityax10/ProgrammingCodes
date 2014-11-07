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

void levelorder(node *t)
{
	queue<node*> v;
	v.push(t);
	while(!v.empty())
	{
		t = v.front();
		v.pop();
		cout<<t->data<<" ";
		
		if(t->l)
		v.push(t->l);
			
		if(t->r)
		v.push(t->r);	
	}
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
	
	levelorder(t);

	return 0;
}


