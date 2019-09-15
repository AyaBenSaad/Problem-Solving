#include <bits/stdc++.h>
 
using namespace std;
 
/*
	Author : Aya Ben Saad
	we will basically simulate the process
	insert all numbers in the set 
	delete all numbers in the set between l and r that are not x
	mark the deleted numbers with x
*/

const int M = 3e5 + 5;
int n, m, l, r, x, ans[M];
set <int> s; 
 
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) s.insert (i);
	s.insert (2e9);
	while (m--) {
		cin >> l >> r >> x;
		auto it = s.lower_bound (l);
		while (*it <= r) {
			if (*it != x){
				ans[*it] = x;
				it = s.erase (it);
			}
			else it++;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	puts("");
}
