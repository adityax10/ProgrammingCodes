#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int a[]={0,1,2,3,4};
	int *p[]={a,a+1,a+2,a+3,a+4};
	int **ptr;
	ptr = p;
	**ptr++;
	cout<<sizeof(char);
	printf("%d",*ptr - a);
	
	return 0;
}

