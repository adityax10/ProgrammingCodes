#include<iostream>

using namespace std;
int x=1;

namespace user1
{
	int x=9;
	
}
using namespace user1;

namespace user2{
	int x=3;
	using namespace user1;
}
using namespace user2;

main()
{
	cout<<user2::x;



   while(1);
}
