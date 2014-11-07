#include <bits/stdc++.h>

using namespace std;

int c=1;

int func()
{
	static int c;
	cout<<c;
}
int main(int argc, char** argv) {
	func();
	return 0;
}

