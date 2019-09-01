#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 5e5 + 5;
int n, a[M], ans;
vector <int> v;
 
void solve() {
    int sz = v.size();
    if(sz == 0) return;
    for(int i = 0; i < sz/2; i++) a[v[i]] = a[v[0]-1];
    for(int i = sz/2; i < sz; i++) a[v[i]] = a[v.back()+1];
    ans = max(ans, (sz+1)/2);
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for(int i = 2; i < n; i++){
        if(a[i] != a[i-1] && a[i] != a[i+1]) v.push_back(i);
        else{solve(); v.clear();}
    }
    solve();
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
}
