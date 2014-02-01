#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int cases;
	cin>>cases;
	int x1,x2,y1,y2;
	int xx1,xx2,yy1,yy2;
	
	int a1,a2;
	
	while(cases--)
	{
		cin>>x1>>y1>>x2>>y2;
		a1 = (x2-x1) * (y2-y1);
		cin>>xx1>>yy1>>xx2>>yy2;
		a2 = (xx2-xx1) * (yy2-yy1);
		
		if((xx1 < x2  && yy1 < y2  && xx2 >x2 && yy2 > y2 )||(xx1 > x2  && yy1 > y2  && xx2 <x2 && yy2 < y2  ))
		{
			int z = (xx1 - x2)*(yy1 - y2);
			cout<<a1+a2-z<<endl;
		}
		else if((xx1 < x2 && yy2 > y1 && xx2>x2 && yy1 < y1) ||(xx1 > x2 && yy2 < y1 && xx2<x2 && yy1 > y1))
		{
			int z = (x2-xx1)*(yy2 - y2);
			cout<<a1+a2-z<<endl;
		}
		else if((xx2 > x1 && yy2 >y1 && xx1<x1 && yy1 < y1) || (xx2 < x1 && yy2 <y1 && xx1>x1 && yy1 > y1))
		{
			int z = (xx2-x1)*(yy2 - y1);
			cout<<a1+a2-z<<endl;
		}
		else if((xx2 > x1 && yy1 < y2 && xx1 <x1 && yy2 >y2) || (xx2 < x1 && yy1 > y2 && xx1 >x1 && yy2 <y2))
		{
			int z = (xx2-x1)*(y2 - yy1);
			cout<<a1+a2-z<<endl;
		}
		else if((xx1 >= x1 && yy1 >= y1 && xx2<=x2 && yy2 <=y2) ||(xx1 <= x1 && yy1 <= y1 && xx2>=x2 && yy2 >=y2))
		{
			if(xx1 > x1)
			cout<<a1<<endl;
			else
			cout<<a2<<endl;
		}
		else
		{
			cout<<a1+a2<<endl;;
		}
		
	}

	return 0;
}


