#include <bits/stdc++.h>
/*
  Author : Aya Ben Saad
  find SCCs, compress every SCC to a node (now we hace a DAG)
  do topological sort
*/ 
using namespace std;
 
const int M = 2e5 + 5;
int n, k, p[M], q[M], cmp;
vector <int> adj[M], g[M];
int dfs, low[M], idx[M], vis[M], ans[M];
vector <int> s;
int where[M], in[M];
map <pair <int, int>, bool > mp;
queue <int> qu;
 
void DFS (int u) {
  low[u] = idx[u] = ++dfs;
  s.push_back(u);
  vis[u] = 1;
  for (int i : adj[u]) {
    if(!idx[i]) DFS(i);
    if (vis[i]) low[u] = min (low[u], low[i]);
  }
  if (idx[u] == low[u]) {
    cmp++;
    while (1) {
      int v = s.back();
      s.pop_back();
      vis[v] = 0;
      where[v] = cmp;
      if (v == u) break;
    }
  }
}
 
int main () {
  scanf ("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
  for (int i = 0; i < n; i++) scanf ("%d", &q[i]);
  p[0]--; q[0]--;
  for (int i = 1; i < n; i++) {
    p[i]--; q[i]--;
    adj[p[i-1]].push_back(p[i]);
    adj[q[i-1]].push_back(q[i]);
  }
  for (int i = 0; i < n; i++) {
    if (!idx[i]) {
      DFS(i);
    }
  }
  for (int i = 1; i < n; i++) {
    if (where[p[i-1]] != where[p[i]]) {
      if (!mp[{where[p[i-1]], where[p[i]]}]) {
        g[where[p[i-1]]].push_back(where[p[i]]);
        in[where[p[i]]]++;
      }
    }
 
    if (where[q[i-1]] != where[q[i]]) {
      if (!mp[{where[q[i-1]], where[q[i]]}]) { 
        g[where[q[i-1]]].push_back(where[q[i]]);
        in[where[q[i]]]++;
      }
    }
  }
  for (int i = 1; i <= cmp; i++) {
    if (!in[i]) qu.push(i);
  }
  int let = 0;
  while (qu.size()) {
    int u = qu.front();
    qu.pop();
    ans[u] = min(let, 25);
    let++;
    for (int i : g[u]) {
      in[i]--;
      if (in[i] == 0) qu.push(i);
    }
  }
  set <char> st;
  string out = "";
  for (int i = 0; i < n; i++) out += ans[where[i]] + 'a', st.insert(out.back());
  if (st.size() < k) {puts("NO"); return 0;}
  cout << "YES\n" << out << endl;
} 
