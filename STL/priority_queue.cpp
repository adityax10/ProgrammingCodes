#include<iostream>
#include<queue>

using namespace std;

class compareClass{
	public:
		bool operator() (int &x,int &y)
		{
			if(x > y)  return true; // for min priority Heap
			//if (y > x) return true; //for max Heap
			else
			return false;
		}
};

int main()
{
	priority_queue<int,vector<int>,compareClass> x;
	
	x.push(3);
	x.push(4);
	x.push(5);
	x.push(1);
	x.push(-1);
	
	cout<<x.top()<<"\n";
	x.pop();
	cout<<x.top()<<"\n";
	
	return 0;
}
