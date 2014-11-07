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

void preorder(node *t)
{
	vector<node*> v;
	while(1)
	{
		while(t)
		{
		//	cout<<"pushed "<<t->data<<endl;
			v.push_back(t);
			cout<<t->data<<" ";
			t=t->l;
		}
		if(v.empty())
		return;
		t = v.back();
		//cout<<"poped "<<t->data<<endl;
	    v.pop_back();
	    t=t->r;
	}
	return ;
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
	
	preorder(t);

	return 0;
}


