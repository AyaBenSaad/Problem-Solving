#include <bits/stdc++.h>

/*
  Author : Aya Ben Saad
  the answer starts with n seats then I calculate the number of needed empty seats 
  it's just the max between left_i and right_i (with both sides sorted)
*/

using namespace std;

int n;
long long ans;
vector<int> l, r;

int main() {
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
    cout << ans << endl;
}
