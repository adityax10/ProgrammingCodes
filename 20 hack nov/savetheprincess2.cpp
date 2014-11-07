#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
/* Head ends here */
void nextMove(int n, int r, int c,int x,int y, vector <string> grid){
    
    bool up=false,down=false,left=false,right=false;
    if(r >= x)
    up=true;
    else
    down=true;
    int v_dis = abs(r-x);
    if(c >= y)
    left=true;
    else
    right=true;
    int h_dis = abs(c-y);
    //cout<<left<<right<<up<<down<<endl;
    if(h_dis>0)
    {
    	if(left)
    	cout<<"LEFT\n";
    	else
    	cout<<"RIGHT\n";
    }
    else if(v_dis>0)
    {
    	if(up)
    	cout<<"UP\n";
    	else
    	cout<<"DOWN\n";
    }
    
}
/* Tail starts here */
int main(void) {

    int n, r, c,x,y=string::npos;
    vector <string> grid;
    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
        if(y==string::npos)
        {
        	y = s.find("p");
        	x=i;
        }
    }
    //cout<<x<<y;
   nextMove(n, r, c, x,y,grid);
    return 0;
}
