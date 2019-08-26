/*
  Author : Aya Ben Saad
  I calculated greedily the sum depending on my current t
  the added value of the answer is num_elements*(t/sum)
  new_t = t % sum
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 2e5 + 5;
int n, a[M];
long long t, ans, sum;

int main () {
  scanf ("%d %lld", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  ans = (t/sum)*n;
  t = t%sum;
  int pre = t;
  do {
    pre = t;
    int k = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i]+sum <= t) {
        k++;
        sum += a[i];
      }
    }
    if (!sum) break;
    ans += (t/sum)*k;
    t %= sum;
  } while (t != pre);
  printf("%lld\n", ans);
}
