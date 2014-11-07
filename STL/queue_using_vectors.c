#include<iostream>
#include<vector>

using namespace std;

int main()
{
	
	vector <int> q;
	
	// vector <int> q(3); => a vector q of 3 elements
	// vector <int> q[3]; => 3 empty vectors => gives error
	
	q.push_front(4);
	q.push_back(5);
	q.push_back(6);
	
	while(q.size())
	{
		//element at the front of vector
		cout<<q.back();
		//element at back of vector ==> q.back();
		
		//pop the last element but doesnt  return it !!
		q.pop_back();
	}
	
	
	
}
