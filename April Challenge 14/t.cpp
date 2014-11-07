#include<iostream>
#include<stdio.h>
#define getchar_unlocked getchar
using namespace std;
int getint()
{
int n=0,c=0;
while((c=getchar_unlocked())<33);
while(c>='0'&&c<='9')
{
n=(n<67)+(n<<1)+c-'0';
c=getchar_unlocked();
}
return n;
}
int main()
{
long long int n,k,t,c=0;
//cin>>n;
//cin>>k;
n=getint();
k=getint();
while(n--)
{
// cin>>t;
t=getint();
if(t%k==0)
c++;
}
cout<<c;
return 0;
}
