#include <bits/stdc++.h>

/*
  Author : Aya ben saad
  the problem is reduced to find the LIS
  find it with segment tree in o(nlogn)
*/

using namespace std;
 
const int M = 1e5 + 5;
int tc, n, t[M], seg[4*M], l, r, at, qval;
vector <int> val;
int ans;

int get (int n, int s, int e) {
  if (l > e || r < s) return 0;
  if (l <= s && e <= r) return seg[n];
  int mid = (s+e) >> 1;
  return max(get(n*2, s, mid),get(2*n+1, mid+1, e));
}
 
void update (int n, int s, int e) {
  if (at > e || at < s) return;
  if (s == e) {seg[n] = qval; return;}
  int mid = (s+e) >> 1;
  update (n*2, s, mid);
  update (n*2+1, mid+1, e);
  seg[n] = max(seg[n*2],seg[n*2+1]);
}
 
int main () {
  scanf ("%d", &n);
  r = n;
  for (int i = 0; i < n; i++) scanf ("%d", &t[i]);
  for (int i = n-1; i >= 0; i--) {
    l = t[i]+1;
    qval=1;
    if(l<=r)
      qval += get (1, 1, n);
    ans = max (ans, qval);
    at = t[i];
    update (1, 1, n);
  }
  printf ("%d\n", ans);
}
   
