#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int> x;
	
	x.push(3);
	x.push(4);
	x.push(5);
	x.push(1);
	
	cout<<x.top();
	x.pop();
	cout<<x.top();
	
	return 0;
}
