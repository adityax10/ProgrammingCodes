#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

int main()
{
	ofstream out("test.txt");
	
	srand(time(NULL));
	int n = 1+rand()%10;
	int m = 6;
	out<<n<<" "<<m<<endl;
	int _m = m;
	while(_m--)
	{
		int x = 1+rand()%n;
		out<<x<<" ";
		int y = 1+rand()%n;
		int y_prev= y;
		while(x--)
		{
			out<<y<<" ";
			while(y<=y_prev)
			{
				y += rand()%n;
			}
			y_prev = y;
		}
		out<<"\n";
	}
}

