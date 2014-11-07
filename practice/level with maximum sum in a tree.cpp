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

int level_with_max_sum(node *t)
{
	int sum[100];
	for(int i=0;i<100;i++)
	sum[i]=0;
	
	
	queue<node *> q;
	
	q.push(t);
	q.push(0);
	
	int level = 0;
	while(1)
	{
		while(q.front()!=0)
		{
			t = q.front();
			q.pop();
			sum[level]+=t->data;
			
			if(t->l)
			{
				q.push(t->l);
			}
			if(t->r)
			{
				q.push(t->r);
			}
		}
		q.pop();
		if(q.size()==0)
		break;
		q.push(0);
		level++;
	}
	for(int i=0;i<=level;i++)
	{
		cout<<sum[i]<<endl;
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
	t->r->l->r=new node(12);
	t->r->l->l=new node(13);
	t->r->l->r->l = new node(11);
	
	level_with_max_sum(t);
	
	return 0;
}


