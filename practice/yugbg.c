#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
 
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
 
using namespace std;
 
typedef long long vlong;
typedef unsigned long long uvlong;
typedef vector < int > vi;
typedef pair < int, int > ii;
typedef pair < vlong, vlong > lili;
typedef vector < ii > vii;
 
template < class T > T sq( T x ) { return x * x; }
 
const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;
 
/***********Template Ends Here***********/
 
int next[200010];
 
vlong path[200010];
vlong cum[200010];
 
vlong mod = 1000000007;
 
int main () {
#ifdef forthright48
//freopen ( "input.txt", "r", stdin );
//freopen ( "output.txt", "w", stdout );
#endif
 
int n;
scanf ( "%d", &n );
 
int b;
scanf ( "%d", &b );
 
int i;
for ( i = 1; i <= n; i++ ) {
scanf ( "%d", &next[i] );
}
 
path[b] = 1;
 
int k = 1;
cum[k++] = 1;
 
for ( i = b - 1; i >= 1; i-- ) {
 
if ( i + next[i] > b ) next[i] = b - i;
if ( next[i] >= k ) next[i] = k - 1;
 
cum[k] = cum[k-1];
int minus = ( k - 1 ) - next[i];
cum[k] -= cum[minus];
path[i] = cum[k] % mod; if ( path[i] < 0 ) path[i] += mod;
cum[k] += cum[k-1];
cum[k] %= mod;
 
k++;
}
 
int q;
scanf ( "%d", &q );
 
while ( q-- ) {
int start;
scanf ( "%d", &start );
printf ( "%lld\n", path[start] );
}
 
 
return 0;
}
