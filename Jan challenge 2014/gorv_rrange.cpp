
#include<vector>
#include<utility>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

vector<pair<long long int ,long long int > > queries;
int  main(){
long long int  N,U,Q;
cin>>N>>U>>Q;
for(long long int  k=1;k<=U;k++){
long long int  i,j;
cin>>i>>j;
queries.push_back(make_pair(i,j));
}
for(long long int  i=1;i<=Q;i++){
long long int  sum=0;
long long int  left;
long long int  a;
long long int  num;
long long int  d=1;
long long int  right;
cin>>left>>right;
for(long long int  j=0;j<U;j++)
{
if((queries[j].first<left && queries[j].second<left) || (queries[j].first>right && queries[j].second>right))
continue;
long long int  distanceleft=queries[j].first-left;
long long int  distanceright=queries[j].second-right;
//cout<<distanceleft<<" "<<distanceright<<"\n";
if(distanceleft<=0 && distanceright<=0){
a=abs(distanceleft)+1;
num=(queries[j].second-left)+1;
}
else if(distanceleft>=0 && distanceright<=0){
a=1;
num=(queries[j].second-queries[j].first)+1;
}
else if(distanceleft>=0 && distanceright>=0){
a=1;
num=(right-queries[j].first)+1;
}
else if(distanceleft<=0 && distanceright>=0){
a=abs(distanceleft)+1;
num=(right-left)+1;
}
//for(long long int  k=a;k<a+num;k++)
//sum=sum+k;
sum=sum+(a*num)+((num*(num-1))/2);
sum%=10000;
}
cout<<sum%10000<<"\n";
}
}


