#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l;
	
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_front(4);
	l.push_front(8);
	//l.erase(pos); =>  deletes an element at position pos from the strating of the doubly linked list
	//l.insert(pos,val); adds the element val before pos
	
	
	while(l.size())
	{
		cout<<l.front();
		l.pop_front();
	}
	
	return 0;
}
