#include <bits/stdc++.h>
 
using namespace std;
 
int q;
int tc, w;
long long u, v;
map <long long, long long> mp;
 
int main () {
  scanf ("%d", &q);
  while (q--) {
    scanf ("%d %lld %lld", &tc, &u, &v);
    if (tc == 1) {
      scanf("%d", &w);
      while (v != u) {
        if (v > u) {mp[v] += w; v /= 2;} 
        else {mp[u] += w; u /= 2;}
      }
    }
    else {
      long long ans = 0;
      while (v != u) {
        if (v > u) {ans += mp[v]; v /= 2;} 
        else {ans += mp[u]; u /= 2;}
      }
      printf ("%lld\n", ans);
    }
  }
}
