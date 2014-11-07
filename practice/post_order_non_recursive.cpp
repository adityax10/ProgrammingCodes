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

void postorder(node *t)
{
	vector<node*> v;
	while(1)
	{
		int x;
		cin>>x;
		//cout<<"l";
		if(t)
		{
			v.push_back(t);
			t=t->l;
	    }
		else
		{
			if(v.back()->r==0)
			{
				t = v.back();
				cout<<t->data<<" ";
				v.pop_back();
				if(t == v.back()->r)
				{
					cout<<v.back()->data<<" ";
					v.pop_back();
				}
			}
			// SOME FUCKING ERROR HERE
			// CORRECT IT
			if(!v.empty())
			t = v.back()->r;
			
		}
		
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
	
	postorder(t);

	return 0;
}


