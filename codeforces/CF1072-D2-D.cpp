#include <bits/stdc++.h>
 
using namespace std;

/*
	for every i, j compute the number of a's it needs so the prefix is fully formed with a's
	then find the cell (i, j) with the maximum level and need[i][j] <= k
	print mx a's
	do a multisource bfs that starts with valid cells (cells with maximal level and need less than k a's)
	for every level in the bfs print the min letter 
	the next bfs will start with cells with that letter and in the same level
*/

const int M = 2e3 + 3;
int n, k;
char t[M][M];
int vis[M][M], need[M][M], used[M][M];

void BFS () {
	priority_queue <pair <int, pair <int, int > > > q;
	vis[0][0] = 1;
	need[0][0] = t[0][0] != 'a';
	q.push({-need[0][0], {0, 0}});
	while (q.size()) {
		auto x = q.top();
		q.pop();
		int u = x.second.first, v = x.second.second;
		if (u+1 < n && !vis[u+1][v]) {
			vis[u+1][v] = vis[u][v]+1;
			need[u+1][v] = need[u][v] + (t[u+1][v] != 'a');
			q.push({-need[u+1][v], {u+1, v}});
		}
		if (v+1 < n && !vis[u][v+1]) {
			vis[u][v+1] = vis[u][v]+1;
			need[u][v+1] = need[u][v] + (t[u][v+1] != 'a');
			q.push({-need[u][v+1], {u, v+1}});
		}
	}
}

int main () {
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> t[i][j];
	BFS();
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << need[i][j] <<  ' ';
			if (need[i][j] <= k) mx = max (mx, vis[i][j]);
		}
		//cout << endl;
	}
	//cout << mx << endl;
	vector <pair <int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == mx && need[i][j] <= k) q.push_back({i, j});
		}
	}
	if (!mx) {
		cout << t[0][0];
		q.push_back({0, 0});
	}
	for (int i = 0; i < mx; i++) cout << 'a';
	while (q.size()) {
		//cout << q.size() << endl;
		char ans = 'z'+1;
		vector <pair <int, int> > nlevel;
		for (auto i : q) {
			int u = i.first, v = i.second;
			if (u+1 < n && used[u+1][v] == 0) {
				used[u+1][v] = 1;
				if (t[u+1][v] < ans) {
					ans = t[u+1][v];
					nlevel.clear();
					nlevel.push_back ({u+1, v});
				}
				else if (t[u+1][v] == ans) nlevel.push_back ({u+1, v});
			}

			if (v+1 < n && used[u][v+1] == 0) {
				used[u][v+1] = 1;
				if (t[u][v+1] < ans) {
					ans = t[u][v+1];
					nlevel.clear();
					nlevel.push_back ({u, v+1});
				}
				else if (t[u][v+1] == ans) nlevel.push_back ({u, v+1});
			}
			//cout << ans;
		}
		//cout << endl;
		if (ans != 'z'+1) cout << ans;
		q = nlevel;
	}
	puts("");
}
