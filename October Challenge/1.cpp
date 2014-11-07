#include<iostream>
#include<limits.h>
#include<cmath>

using namespace std;

int main()
{
	int x1,y1,x2,y2,x3,y3;
	int cases,index;
	int max_index=0,min_index=0;
	double max_area=INT_MIN,min_area=INT_MAX,area;
	
	cin>> cases;
	for(int i=1;i<=cases;i++)
	{
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 area=abs((double)(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
	 index=i;
	 
	 if(max_area <= area)
	 {
	 	max_index=i;
	 	max_area=area;
	 }
	 if(min_area >= area)
	 {
	 	min_index=i;
	 	min_area=area;
	 }
	 //cout<<min_area<<" "<<max_area;
    }
    
    cout<<min_index<<" "<<max_index<<"\n";
    
    return 0;
}
