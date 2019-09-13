#include <bits/stdc++.h>
 
using namespace std; 

/*
	Author : Aya Ben Saad
	for every node node we precompute a list of good edges 
	we decide whether an edge (u, v) is good or not after precomputing the bfs level of each node
	if dis[u] == dis[v] + 1 than edge (u, v) is good for u;
	the we compute possible answers by looping through every good edges' list for every node 
*/
 
const int M = 2e5 + 5;
int n, m, k, u[M], v[M];
vector <int> adj[M], good[M];
int vis[M], where[M];
vector <string> ans;
 
void BFS (int u) {
	queue <int> q;
	q.push(u);
	vis[u] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i : adj[x]) {
			if (vis[i]) continue;
			vis[i] = vis[x]+1;
			q.push(i);
		}
	}
}
 
void find_good_ed () {
	for (int i = 0; i < m; i++) {
		//cout << u[i] << ' ' << v[i] << '*' << vis[u[i]] << ' ' << vis[v[i]] << endl;
		if (vis[u[i]] == vis[v[i]]+1) good[u[i]].push_back(i);
		if (vis[v[i]] == vis[u[i]]+1) good[v[i]].push_back(i);
		//cout << good[u[i]].size() << ' ' << good[v[i]].size() << endl;
	}
}
 
int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u[i], &v[i]);
		--u[i], --v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	BFS (0);
	find_good_ed();
	//for (int i = 0; i < n; i++) cout << good[i].size() << ' ';
	//puts("");
	while (ans.size() < k) {
		//for (int i = 0; i < n; i++) cout << where[i] << ' ';
		//cout << endl;
		string s = "";
		for (int i = 0; i < m; i++) s += '0';
		for (int i = 0; i < n; i++) if (where[i] < good[i].size()) s[good[i][where[i]]] = '1';
		ans.push_back(s);
		for (int i = 0; i < n; i++) {
			if (where[i]+1 < good[i].size()) {
				where[i]++;
				goto ok;
			}
			where[i] = 0;
		}
		break;
		ok:;
	}
	printf("%d\n", ans.size());
	for (auto i : ans) cout << i << endl;
}
