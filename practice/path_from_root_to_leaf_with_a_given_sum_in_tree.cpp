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

bool check_sum(node *t,int sum)
{
	if(!t)
	return sum==0;
	
	return check_sum(t->l,sum - t->data)+check_sum(t->r,sum- t->data);
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
	
	cout<<check_sum(t,8);
	
	return 0;
}


