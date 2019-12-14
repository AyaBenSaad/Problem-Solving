#include <bits/stdc++.h>
 
/*
for every vertical spell we need to compute the number of horizental spells that
we need to delete and obviously we will add the rest of vertical spells

*/

using namespace std;
 
const int M = 1e9;
int n, m, x, x1, x2, y, ans;
vector <int> col, ln;
 
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); 
		col.push_back(x);
	}
	sort(col.begin(), col.end());
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &x1, &x2, &y);
		if (x1 == 1) ln.push_back(x2);
	}
	sort(ln.begin(), ln.end());
	ans = n + m;
	for (int i = 0; i < col.size(); i++){
		int pos = lower_bound(ln.begin(), ln.end(), col[i]) - ln.begin();
		int nd = ln.size() - pos;
		ans = min(ans, i + nd);
	}
	int pos = lower_bound(ln.begin(), ln.end(), M) - ln.begin();
	int nd = ln.size() - pos;
	ans = min(ans, (int)col.size() + nd);
	printf("%d\n", ans);
}
 
