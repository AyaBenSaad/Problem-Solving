#include <bits/stdc++.h>

/*
  Author : Aya Ben Saad
  I used priority queues to get the mid one for the left part and one for the right part 
*/

using namespace std;
 
const int MOD = 1e9 + 7;
int t;

int main() {
  scanf ("%d", &t);
  for(int i=0; i<t; i++) {
    int n;
    long long a,b,c;
    priority_queue <long long, vector<long long>, greater<long long> > l;
    priority_queue <long long> r;
    long long ans = 0, mid = 0;
    scanf ("%lld %lld %lld %d", &a, &b, &c, &n);          
    if(n == 1) {puts("1"); continue;}        
    r.push(1);   
    ans += 1;        
    for(int j = 2; j <= n; j++) {
      if(r.size() >= l.size()) mid = r.top();
      else mid = l.top();                
      long long x = (a*mid + b*j + c) % MOD;
      ans += x;                        
      if(x <= r.top()) r.push(x);
      else l.push(x);
      long long a = l.size(), b = r.size();      
      if (a - b > 1) {r.push(l.top()); l.pop();}
      else if(b - a > 1) {l.push(r.top()); r.pop();}
    }
    cout << ans << endl;
  }
}
