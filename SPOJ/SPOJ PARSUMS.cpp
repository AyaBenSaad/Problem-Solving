#include <bits/stdc++.h>

using namespace std;

const int M = 1e6+6;
int n, a[2*M], ans;

int main() {
  while (cin >> n && n != 0) {
    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[n+i] = a[i];
    }
    long long sum = 0;
    for (int i = 2*n-1; i >= 0; i--) {
      sum += a[i];
      if (sum < 0) continue;
      if (i < n) ans++;
      sum = 0;
    }
    cout << ans << endl;
  }
}
