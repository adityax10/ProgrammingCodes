#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> x;
	
	x.push(3);
	x.push(4);
	x.push(5);
	
	queue<int> y = x;
	
	while(!y.empty())
	{
	cout<<y.front();
	y.pop();
    }
	//cout<<y.front();
	cout<<x.front();
}
