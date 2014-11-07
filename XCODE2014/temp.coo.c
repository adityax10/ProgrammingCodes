#include <iostream>
#include <algorithm>
using namespace std;
#define M 1010
int x[M], y[M];
int n;
int s[M];
bool vis[M];
 
int dist(int i, int j){
return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
 
int main(){
// freopen("in.txt", "r", stdin);
int i, j, k;
scanf("%d", &n);
for(i=1; i<=n+1; i++)scanf("%d %d", x+i, y+i);
 
int mn;
for(i=0; i<=n; i++)s[i]=dist(n+1, i);
while(1){
k=-1;
for(i=0; i<=n; i++)if(!vis[i]){
if(k==-1 || mn>s[i])mn=s[i], k=i;
}
for(i=0; i<=n; i++)if(!vis[i]){
int x=dist(i,k);
if(s[i]>x+s[k])s[i]=x+s[k];
}
vis[k]=1;
if(!k)break;
}
printf("%d\n", s[0]);
return 0;
}
