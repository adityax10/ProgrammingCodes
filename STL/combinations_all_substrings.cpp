// Program to print all combination of size r in an array of size n
#include <iostream>
#include<string>
#include<map>

using namespace std;

map <string,bool> visited_map;


void combinationUtil(char arr[], char data[], int start, int end, int index, int r);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(char arr[], int n)
{
    // A temporary array to store all combination one by one
    char data[n];
    for(int r=1;r<=n;r++)
    {
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
    }
}
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(char arr[], char data[], int start, int end, int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
    	data[r]=NULL;
    	string temp(data);
    	
    	if(!visited_map[temp])
    	{
    		cout<<temp;
	        visited_map[temp]=1;
	        cout<<endl;
        } 
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

// Driver program to test above functions
int main()
{
    char arr[] = {'1','1','3','4'};
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n);
}
