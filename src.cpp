/*
  Author : Aya Ben Saad
  brute force on all number combinations and count how many possibility fits with the data 
  it should be unique 
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 15;
int n, ans;
string s[M];
int a[M], b[M];
vector <string> d;

bool ok (string k) {
  for (int i = 0; i < n; i++) {
    int tot = 0;
    string x = s[i];
    sort (x.begin(), x.end());
    for (char c  : k) {
      if (*lower_bound (x.begin(), x.end(), c) == c) tot++;
    }
    int bl = 0;
    for (int j = 0; j < 4; j++) {
      if (s[i][j] == k[j]) bl++, tot--;
    }
    if (bl != a[i] || tot != b[i]) return 0;
  }
  return 1;
}

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i] >> b[i];
    if (s[i].size() == 3) s[i] = '0'+s[i];
  }
  for (char i = '0'; i <= '9'; i++) {
   bool v[M] = {0};
    v[i-'0'] = 1;
    string k = "";
    k += i;
    for (char j = '0'; j <= '9'; j++) {
      if (v[j-'0']) continue;
      v[j-'0'] = 1;
      k += j;
      for (int l = '0'; l <= '9'; l++) {
        if (v[l-'0']) continue;
        v[l-'0'] = 1;
        k += l;
        for (int m = '0'; m <= '9'; m++) {
          if (v[m-'0']) continue;
          v[m-'0'] = 1;
          k += m;
          if (ok(k)) d.push_back(k);
          ans++;
          k.pop_back();
          v[m-'0'] = 0;
        }
        k.pop_back();
        v[l-'0'] = 0;
      }
      k.pop_back();
      v[j-'0'] = 0;
    }
  }
  if (d.size() == 0) {puts("Incorrect data"); return 0;}
  if (d.size() > 1) {puts("Need more data"); return 0;}
  cout << d[0] << endl;
}