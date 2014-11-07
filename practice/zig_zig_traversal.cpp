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
	vector<node*> s;
	queue<node*> q;
	
	s.push_back(t);
	
	while(!s.empty() || !q.empty())
	{
		// stack
		while(!s.empty())
		{
			t = s.back();
			s.pop_back();
			cout<<t->data<<" ";
			if(t->r)
			q.push(t->r);
			
			if(t->l)
			q.push(t->l);
		}
		
		// Queue
		while(!q.empty())
		{
			t = q.front();
			q.pop();
			cout<<t->data<<" ";
			
			if(t->r)
			s.push_back(t->r);	
			
			if(t->l)
			s.push_back(t->l);	
		}
		
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
	
	inorder(t);

	return 0;
}


