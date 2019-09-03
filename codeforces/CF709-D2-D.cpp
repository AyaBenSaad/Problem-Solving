#include <bits/stdc++.h>

/*
  Author : Aya Ben Saad
  the number of needed zeros x and the number of needed ones y
  x is the smallest possible number greater than a
  y is the smallest possible number greater than d
  check if it is possible to build a string with x zeros and y ones 
  if yes put ones and zeros alternativly dpending on c
*/
 
using namespace std;
 
int a, b, c, d;
string s;
 
int main() {
  cin >> a >> b >> c >> d;
  int x = 0, y = 0;
  while (x*(x-1)/2 < a) x++;
  while (y*(y-1)/2 < d) y++;
  if (a+b+c+d == 0) {puts ("0"); return 0;}
  if (x*(x-1)/2 != a || y*(y-1)/2 != d || x * y != b + c) {
    if (x*(x-1)/2 == a && y*(y-1)/2 == d) {x = max(x, 1); y = max(y, 1);}
    if (x*(x-1)/2 != a || y*(y-1)/2 != d || x * y != b + c) {puts("Impossible"); return 0;}
  }
  int l = x + y;
  for (int i = 0; i < l; i++) {
    if (c >= x) {y--; c -= x; s += '1';}
    else {x--; s += "0";}
  }
  cout << s << endl;
}
