#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue <int> q;
	
	q.push(4);
	q.push(5);
	q.push(6); 
	
	
	
	while(q.size())
	{
	cout<<q.front(); // q.back() for back
	q.pop();
    }
	return 0;
}
