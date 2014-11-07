#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

double find_area(int p[][2],int n)
{
	double area = 0;
	for(int i=1;i+1<n;i++)
	{
		int x1 = p[i][0]-p[0][0];
		int y1 = p[i][1]-p[0][1];
		int x2 = p[i+1][0]-p[0][0];
		int y2 = p[i+1][1]-p[0][1];
		
		area += x1*y2 - x2*y1;
	}
	return abs(area/2);
}

int main()
{
	int n = 4;
	//int q[2][2]={{2,3},{3,3}};
	// pass coordindate in order (cyclic ) /or/ anti Cyclic wrt (p[0]][0] , p[0][1])
	int p[][2]={{1,0},{0,1},{3,1},{2,0}};
	cout<<find_area(p,n);
	return 0;
}


