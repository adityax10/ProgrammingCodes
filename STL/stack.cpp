#include<iostream>
#include<stack>

using namespace std;

int main()
{
	
	stack<int> q;
	int a;
	
	// vector <int> q(3); => a vector q of 3 elements
	// vector <int> q[3]; => 3 empty vectors => gives error
	
	q.push(4);
	q.push(5);
	q.push(6);
	
	
	while(q.size())
	{
		//element at the front of vector
		cout<<q.top();
		//element at back of vector ==> q.back();
		
		//pop the last element but doesnt  return it !!
		q.pop();
	}
	
	
	
}
