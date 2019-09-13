#include <bits/stdc++.h>

using namespace std;
/*
	Author : Aya Ben Saad
	if k is even then there is no solution
	otherwise we need 4k-2 nodes : two SCC and a bridge connecting them
*/
int k;
vector< pair<int, int> > ans;

int main() {
	cin >> k;
	int n = 4*k-2;
	if (k % 2 == 0) {puts("NO"); return 0;}
	puts("YES");
	for (int i = 2; i <= k; i++) {
		ans.push_back({1, i});
		for (int j = k+1; j < 2*k; j++) ans.push_back({i, j});
	}
	for (int i = k+1; i < 2*k; i += 2) ans.push_back({i, i+1});
	int m = 2*ans.size()+1;
	cout << n << ' ' << m << endl;
	cout << "1 " << 2*k << endl;
	for (auto i : ans)
		cout << i.first << ' ' << i.second << ' ' << i.first+2*k-1 << ' ' << i.second+2*k-1 << endl;
}
