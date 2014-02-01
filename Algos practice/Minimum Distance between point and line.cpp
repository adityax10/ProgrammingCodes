#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int dot_product(int a[2],int b[2],int c[2])
{
	int ab[2];
	int bc[2];
	ab[0] = b[0]-a[0];
	ab[1]= b[1]-a[1];
	bc[0] = c[0] - b[0];
	bc[1] = c[1] - b[1];
	return ab[0]*bc[0] + ab[1]*bc[1];	
}

int cross_product(int a[2],int b[2],int c[2])
{
	int ab[2];
	int bc[2];
	ab[0] = a[0]-b[0];
	ab[1]= a[1]-b[1];
	bc[0] = c[0] - b[0];
	bc[1] = c[1] - b[1];
	return ab[0]*bc[1] - ab[1]*bc[0];
}

double magnitue(int a[2],int b[2])
{
	return sqrt((b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]));
}

double find_distance(int a[],int b[],int c[],bool is_line_segment)
{
	if(is_line_segment)
	{
		int d1 = dot_product(a,b,c);
		if(d1>0)
		return magnitue(b,c);
		int d2 = dot_product(b,a,c);
		if(d2>0)
		return magnitue(a,c);
	} 	
	double dist = 	cross_product(a,b,c) / magnitue(a,b);
	return abs(dist);
}

void initiate_point(int a[],int x,int y)
{
	a[0]=x;
	a[1]=y;
}

int main()
{
	int a[2],b[2],c[2];
	initiate_point(a,1,1);
	initiate_point(b,4,1);
	initiate_point(c,5,2);
	cout<<find_distance(a,b,c,1);
	return 0;
}


