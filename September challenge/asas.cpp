#include<iostream>
using namespace std;


template<class T> void func(T ob)
{
	cout<<"General";
}

template<> void func<int>(int ob)
{
	cout<<"Specialisation";
}

int main()
{
	func<double>(1);
	func<int>(2.3);
}
