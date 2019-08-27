/*
  Author : Aya Ben Saad
  binary search the answer 
  if the answer is x then try to fill the smallest k elments from array b 
  handle the ones alone 
*/
#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define fi first
#define se second
 
using namespace std;
 
const int M = 1e6 + 6;
int n, m, a[M], b[M], p[40];
long long h = 0;
 
void pre_pow () {
  int r = 1;
  for (int i = 0; i < 30; i++) {
    p[i] = r;
    r *= 2;
  }
}
 
bool ok (int x) {
  int k = 0, ls = 0, one = 0;
  long long sum = 0, ret = 0;
  sort (b, b+x, greater <int> ());
  vector <int> v;
  for (int i = 0; i < x; i++) {
    if (b[i] == 1) one ++;
    else v.push_back (b[i]);
  }
  for (int i = 0; i < (int) v.size(); i++) {
    if (k == n) {sort (b, b+x); return 0;}
    while (k < n && a[k]-ls < v[i]) {k++; ls = 0;}
    if (k < n && a[k]-ls >= v[i]) {sum += v[i]; ls += v[i]; ret ++;}
    //if(x == 2) cout << i << ' ' << ls << endl;
  }
  //cout << x << ' ' << k << ' ' << ls << endl;
  sort (b, b+x);
  ret += min (1ll*one, h-sum);
 // if (x == 10) cout << one << ' ' << h << endl;
  return 1ll*ret >= 1ll*x;
}
 
int main () {
  pre_pow();
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf ("%d", &a[i]), h+=a[i];
  for (int i = 0; i < m; i++) {
    int x;
    scanf ("%d", &x);
    b[i] = p[x];
  }
  sort (a, a+n, greater <int> ());
  sort (b, b+m);
  int l = 0, r = m;
  while (l < r) {
    int mid = (l+r+1)/2;
    if (ok(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
}
