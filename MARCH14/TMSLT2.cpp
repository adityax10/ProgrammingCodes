#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
 
#define lli long long int
 
inline lli read()
{
int flag=1;
lli n = 0;
char c;
int parity=1;
int i=0;
while (1)
{
c=GETCHAR();
if(i==0&&c=='-') parity=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
i++;
}
return parity*n;
}
 
inline void write(long long x)
{
int i = 20;
char buf[21];
buf[20] = '\n';
do
{
buf[--i] = x % 10 + '0';
x/= 10;
}while(x);
do
{
PUTCHAR(buf[i]);
} while (buf[i++] != '\n');
}
 
inline int mulmod(lli a,lli b,lli c){
lli x = 0,y=a%c;
while(b > 0){
if(b%2 == 1){
x = (x+y)%c;
}
y = (y*2)%c;
b /= 2;
}
return x%c;
}
 
using namespace std;
 
lli v[3000005];
 
int main()
{
int cases,n,_n,a,b,c,d;
lli sum1,sum2;
lli prev_v;
cases = read();
while(cases--)
{	
	n = read();
	a = read();
	b = read();
	c = read();
	d = read();
	v[0] = d ;
	prev_v = v[0];
	_n = n;
	if(_n==1)
	{
	write(d);
	continue;
	}
	n--;
	int i =1;
	while(n--)
	{
	prev_v = (a*prev_v*prev_v + b*prev_v + c)%1000000;
	v[i++] = prev_v;
	}
	sort(v,v+_n);
	sum1=0,sum2=0;
	for(int i=0;i<_n;i+=2)
	sum1 += v[i];
	for(int i=1;i<_n;i+=2)
	sum2 += v[i];
	cout<<"S1 "<<sum1<<" " <<sum2<<endl;
	write(((sum1-sum2)>0)?(sum1-sum2):(sum2-sum1));
}
 
return 0;
}
 
