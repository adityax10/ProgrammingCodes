#include<stdio.h>
int A[100];
int find_largest_sum(int A[],int n_elements){



int largest=A[0]; int tmp=A[0]; for(int i=1;i<n_elements;++i) { if(tmp+A[i] > A[i]) tmp+=A[i]; else tmp=A[i]; if(tmp>largest) largest=tmp; } return largest; } int main(){ int count; printf("Enter the no. of elements\n"); scanf("%d",&count); for(int i=0;i<count;++i) scanf("%d",&A[i]); int l_sum=find_largest_sum(A,count); printf("largest sum is %d\n",l_sum); return 0; } 
