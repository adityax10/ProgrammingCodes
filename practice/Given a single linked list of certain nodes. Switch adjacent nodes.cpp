#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *link;
	node(int d)
	{
		data = d;
		this->link = 0;
	}
	
	// list size >=2
	node *switch_adjacent(node *list)
	{
		node *s = list;
		node *n = s->link;
		node *p = n->link;
		list = n;
		
		while(1)
		{
			s->link = p;
			n->link = s;
			if(p && p->link)
			{
				s->link = p->link;
				s=p;
				n = p->link;
				p=n->link;
			}
			else
			break;
		}
		return list;
	}
	
	void print()
	{
		node *list = this;
		while(list)
		{
			cout<<list->data<<" ";
			list = list ->link;
		}
		cout<<endl;
	}
};

int main()
{
	node *list;
	list = new node(1);
	list->link = new node(2);
	list->link->link =new node(3);
	list->link->link->link = new node(4);
	
	list->print();
	
	list = list->switch_adjacent(list);
	list->print();
	
	return 0;
}


