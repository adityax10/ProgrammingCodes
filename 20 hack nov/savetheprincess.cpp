#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
	
	bool top=false,bottom=false,left=false,right=false;
    if(grid[0][0]=='p' || grid[0][n-1]=='p')
    {
    	top=true;
    	if(grid[0][0]=='p')
    	left=true;
    	else
    	right=true;
    }
    else if(grid[n-1][0]=='p' || grid[n-1][n-1]=='p')
    {
    	bottom=true;
    	
    	if(grid[n-1][0]=='p')
    	left=true;
    	else
    	right=true;
    }
    
    for(int i=0;i<n/2;i++)
    {
    	if(top==true)
    	{
    		cout<<"UP\n";
    	}else
    	{
    		cout<<"DOWN\n";
    	}
    	if(left==true)
    	{
    		cout<<"LEFT\n";
    	}
    	else 
    	{
    		cout<<"RIGHT\n";
    	}
    }
       
}
/* Tail starts here */
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }
	displayPathtoPrincess(m,grid);

    return 0;
}
