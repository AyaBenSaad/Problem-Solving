#include <bits/stdc++.h>

using namespace std;

/*
  Author : Aya Ben Saad
  binary search the answer and for every mid check it it needs less than m days
  we do that by simulating the process exactly with some optimization
*/

const int M = 2e5 + 5;
int n, w, m;
long long  t[M];

bool ok (long long tr){
  long long f[M] = {0};
  long long cr = 0, inter = 0, x;
  for(int i = 0; i < n; i++){
    cr -= f[i];
    x = max(0ll, tr - t[i] - cr);
    inter += x;
    cr += x;
    f[i+w] += x;
  }
  return inter <= m;
}

int main () {
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) cin >> t[i];
  long long l = 1, r = 1e10;
  while (l < r) {
    long long mid = (l+r+1)/2;
    if (ok(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
}
