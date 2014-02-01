
#include<iostream>
#include<stdlib.h>
using namespace std;

class a
{
public:
a(){cout<<"a is created"<<endl;}
~a(){cout<<"a is destroyed"<<endl;}
};

class b:public a
{
public:
b(){cout<<"b is created"<<endl;}
~b(){cout<<"b is destroyed"<<endl;}
};

int main()
{
a *aptr=new b;
delete aptr;
return 0;
}
