//#include<iostream>
using namespace std;
//#include<conio.h>
void f(char * x)
{
  x++;
  *x = 'a';
}
int main()
{
  char * str = "hello";
  f(str);
  cout << str;
  system("pause");
  return 0;
} 
