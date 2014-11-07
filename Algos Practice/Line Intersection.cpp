#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int get_intersection_points(int l1[2][2],int l2[2][2])
{
	int x1 = l1[0][0];
	int y1 = l1[0][1];
	int x2 = l1[1][0];
	int y2 = l1[1][1];
	
	int a1= x1-x2;
	int b1 =y2-y1;
	int c1 = y1*b1 + x1*a1;
	
	x1 = l2[0][0];
	y1 = l2[0][1];
	x2 = l2[1][0];
	y2 = l2[1][1];
	
	int a2= x1-x2;
	int b2 =y2-y1;
	int c2 = y1*b2 + x1*a2;	
	int det = a1*b2 - a2*b1;
	if(det==0)
	{
		cout<<"Parallel Lines\n";
	}
	else
	{
		double x = (double)(c1*b2 - c2*b1)/det;
		double y = (double)(c2*a1 - c1*a2)/det;
		cout<<x<<" "<<y<<endl; 
	}
}

int main()
{
	int l1[2][2]={{0,0},{1,1}};
	int l2[2][2]={{1,0},{0,1}};
	get_intersection_points(l1,l2);
	return 0;
}


