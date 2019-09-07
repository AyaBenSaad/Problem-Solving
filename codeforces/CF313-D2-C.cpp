#include <bits/stdc++.h>

using namespace std;

/*
  Author : Aya Ben Saad
  sort the elements in increasing order 
  and the for every x = 4^y add the last x elements to the answer 
*/

const int M = 2e6 + 6;
int n, t[M];
long long ans;

int main() {
  scanf ("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", t+i);
  sort(t, t+n);
  for(int i = 1; i <= n; i *= 4) {
    for(int j = n-1; j >= n-i; j--) ans += t[j];
  }
  cout << ans << endl;
}
