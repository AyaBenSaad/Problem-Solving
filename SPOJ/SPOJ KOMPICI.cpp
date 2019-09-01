#include <bits/stdc++.h>

/*
  Author: Aya Ben Saad
  I represent all the numbers with masks where the ith bit represents whether digit i is present or not 
  for every possible mask (which are only 2^10 = 1024) I precompute how many number sharing at least one turned on bit
  then I sum all the results for the n masks
  I print the result divided by two since every pair is computed twice
*/
 
using namespace std;
 
const int M = 5e5 + 5;
int n;
long long a[M]; 
unsigned int mask[M];
int res[1024+3];
long long ans = 0;

int main () {
  scanf ("%d", &n); 
  for (int i = 0; i < n; i++) {
    scanf ("%lld", &a[i]);
    long long x = a[i];
    while (x) {
      int j = x%10;
      x /= 10;
      mask[i] |= (1 << j);
    }
  }
  for (unsigned int ms = 0; ms <= 1024; ms++) {
    for (int i = 0; i < n; i++) {
      res[ms] += (bool)(ms & mask[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    ans += res[mask[i]] - 1;
  }
  cout << ans/2ll << endl;
}
