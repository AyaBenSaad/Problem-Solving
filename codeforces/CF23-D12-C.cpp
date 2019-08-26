/*
  Author : Aya Ben Saad
  I tied odd positions and even positions in the sorted array 
*/
#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define fi first
#define se second
 
using namespace std;
 
int t;

int main () {
  scanf ("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    n *= 2;
    n--;
    pair <pair <int, int>, int > a[n+1];
    long long ap = 0, og = 0;
    set <int> s;
    for (int i = 0; i < n; i++) {
      s.insert (i);
      scanf ("%d %d", &a[i].first.first, &a[i].first.second);
      ap += a[i].first.first;
      og += a[i].first.second;
      a[i].second = i+1;
    }
    sort (a, a+n);
    long long x = 0, y = 0, d = 0, f = 0;
    for (int i = 0; i < n; i += 2) {
      x += a[i].first.first;
      y += a[i].first.second;
    }
    for (int i = 1; i < n; i += 2) {
      d += a[i].first.first;
      f += a[i].first.second;
    }
    d += a[n-1].first.first;
    f += a[n-1].first.second;
    if ((x < ap/2+ap%2 || y < og/2+og%2) && (d < ap/2+ap%2 || f < og/2+og%2)) {puts("NO"); continue;}
    puts("YES");
    if ((d < ap/2+ap%2 || f < og/2+og%2)) for (int i = 0; i < n; i += 2) cout << a[i].second << ' ';
    else {for (int i = 1; i < n; i += 2) cout << a[i].second << ' ';
    cout << a[n-1].second;}
    puts("");
  }
}
